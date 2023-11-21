#include "robot/include/robot_positionController.hpp"
#include "myactuator_rmd/motorInfo.hpp"


namespace robot{


        robotPositionController::robotPositionController(float pGain, float iGain,float dGain) 
        :  proportionalGain(pGain),  derivativeGain(dGain),integralGain(iGain)
        {   
            // inner_driver_->MotorRunning();
            // myactuator_rmd::Feedback buf;
            // buf = inner_driver_->sendTorqueSetpoint(0);
            // previousShaftAngle = buf.shaft_angle;
        }

        robotPositionController::~robotPositionController()
        {}

        void robotPositionController::addMotor(std::uint32_t actuator_id)
        {
            inner_driver_->addMotor(actuator_id);
            inner_driver_->MotorRunning(actuator_id);
            std::cout << "Motor set" << std::endl;
            Feedback buf {inner_driver_->sendTorqueSetpoint(actuator_id,0)};
            std::cout << "Motor torque 0 set" << std::endl;
            previousShaftAngle.push_back(buf.shaft_angle);
            currentAngle.push_back(0);
            std::cout << currentAngle.size() << std::endl;
            sleep(5);
        }

        void MotorPositionController::showCurrentAngle(std::uint32_t actuator_id)
        {
           std::cout << currentAngle[actuator_id-1] << std::endl;
        }

        void MotorPositionController::PIDcontrol(std::vector<std::uint32_t> actuator_id, std::vector<double> setpoint, int maxIterations)
        {
            int iteration = 0;
   
            const size_t dimension = actuator_id.size();

            std::vector<double> error(dimension, 0.0);
            std::vector<double> previousError(dimension, 0.0);
            std::vector<double> integralError(dimension, 0.0);
            std::vector<double> derivativeError(dimension, 0.0);
            std::vector<double> controlSignal(dimension, 0.0);


            auto start_freq = std::chrono::high_resolution_clock::now();
            auto end_freq = std::chrono::high_resolution_clock::now();
            auto dTime1 = std::chrono::high_resolution_clock::now();
            auto dTime2 = std::chrono::high_resolution_clock::now();
            double dt = 0;

            do {
                ///

                for (size_t i = 0; i < dimension; ++i) {

                    error[i] = setpoint[i] - currentAngle[actuator_id[i] - 1];

                    integralError[i] += error[i];               // Accumulate the integral error
                    if (dt > 0) { derivativeError[i] = (error[i] - previousError[i]) / dt;}

                }
                                     
                dTime2 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> dt_ = dTime2 -dTime1;
                dt = dt_.count();


                for(size_t i =0; i< dimension; ++i){

                controlSignal[i] = proportionalGain * error[i] + integralGain * integralError[i] + derivativeGain * derivativeError[i];
                std::cout << "Signal " << i << " " << controlSignal[i] << std::endl;
                if(error[i]<errorThreshold) controlSignal[i] = 0;
                actuateMotor(actuator_id[i], controlSignal[i]);

                
                 
                }


                for(size_t i =0; i< dimension; ++i){
                
                if(error[i]<errorThreshold) controlSignal[i] = 0;
                actuateMotor(actuator_id[i], controlSignal[i]);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));


                }



                previousError[0] = error[0];
                previousError[1] = error[1];

                dTime1 = dTime2;
                
               
                iteration++;

                // Display Frequency
                // if(iteration >200)
                // {
                //     end_freq = std::chrono::high_resolution_clock::now();
                //     std::chrono::duration<double> duration = end_freq - start_freq;
                //     auto seconds =duration.count();
                //     std::cout << " Frequency : " << iteration/seconds << " Angle : " << currentAngle[actuator_id]<< std::endl;
                //     iteration = 0;
                //     start_freq = std::chrono::high_resolution_clock::now();
                // }
            } while ((controlSignal[0]!=0)||(controlSignal[1]!=0));

        }

    
        void robotPositionController::updateMotorPosition(std::uint32_t actuator_id, Feedback feedback) 
        {
            int currentShaftAngle = feedback.shaft_angle;
            calculateCurrentAngle(actuator_id, currentShaftAngle);
            mtx.lock();
            previousShaftAngle[actuator_id -1] = currentShaftAngle;
            mtx.unlock();
        }

        void robotPositionController::calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle)
        {    

            float shaftChange =0;
            if (currentShaftAngle - previousShaftAngle[actuator_id-1] > 40000) {
                // carry += (currentShaftAngle < previousShaftAngle) ? 1 : -1;
                shaftChange = -((maxShaftAngle - currentShaftAngle) + previousShaftAngle[actuator_id-1]);
            }
            if (currentShaftAngle - previousShaftAngle[actuator_id-1] < -40000) {
                // carry += (currentShaftAngle < previousShaftAngle) ? 1 : -1;
                shaftChange = currentShaftAngle + (maxShaftAngle - previousShaftAngle[actuator_id-1]);
            }
            else
            {
                shaftChange = currentShaftAngle - previousShaftAngle[actuator_id-1];
            }
            mtx.lock();
            currentAngle[actuator_id-1] += shaftChange/maxShaftAngle*oneShaftCycle;
            mtx.unlock();
            showCurrentAngle(actuator_id);
        }

        void robotPositionController::actuateMotor(std::uint32_t actuator_id, float controlSignal) 
        {   
            Feedback buf;
            // Clamping controlSignal to the range of -20.0 to 20.0
            float clampedSignal = std::max(-20.0f, std::min(controlSignal, 20.0f));
            buf = inner_driver_->sendTorqueSetpoint(actuator_id, clampedSignal);
            updateMotorPosition(actuator_id,buf);
        }
};


