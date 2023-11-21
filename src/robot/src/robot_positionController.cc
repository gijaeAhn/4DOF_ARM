#include "robot_positionController.hpp"
#include "myactuator_rmd/motorInfo.hpp"



namespace robot{


        robotPositionController::robotPositionController(float pGain, float iGain,float dGain,Robot* robot) 
        :  proportionalGain(pGain),  derivativeGain(dGain),integralGain(iGain), robot_(robot)
        {   }

        robotPositionController::~robotPositionController()
        {}

        



        void robotPositionController::PIDcontrol(std::vector<std::uint32_t> actuator_id, std::vector<double> setpoint, int maxIterations)
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

                    error[i] = setpoint[i] - robot_->currentAngle[actuator_id[i] - 1];

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
                robot_->actuateMotor(actuator_id[i], controlSignal[i]);

                
                 
                }


                for(size_t i =0; i< dimension; ++i){
                
                if(error[i]<errorThreshold) controlSignal[i] = 0;
                robot_->actuateMotor(actuator_id[i], controlSignal[i]);
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

    
        
};


