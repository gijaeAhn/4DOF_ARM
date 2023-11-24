#include "controller/robot_positionController.hpp"




namespace robot{


        robotPositionController::robotPositionController(float pGain, float iGain,float dGain,Robot* robot) 
        :  proportionalGain(pGain),  derivativeGain(dGain),integralGain(iGain), robot_(robot), PID_SHM(PID_CONTROL_KEY,ROBOT_MEM_SIZE)
        {  
            PID_SHM.SHM_GETID();
            for ( int i =0; i <ROBOT_MEM_SIZE; i++){
                signal[i] =0;
            }
        }

        robotPositionController::~robotPositionController()
        {   
            PID_SHM.SHM_FREE();
            
        
        }

        



        void robotPositionController::PIDcontrol(std::vector<double> setpoint)
        {

            std::cout<<"PID CONTROL" << std::endl;
            // int iteration = 0;
   
            // const size_t dimension = actuator_id.size();

            // std::vector<double> error(dimension, 0.0);
            // std::vector<double> previousError(dimension, 0.0);
            // std::vector<double> integralError(dimension, 0.0);
            // std::vector<double> derivativeError(dimension, 0.0);
            // std::vector<double> controlSignal(dimension, 0.0);


            // auto start_freq = std::chrono::high_resolution_clock::now();
            // auto end_freq = std::chrono::high_resolution_clock::now();
            // auto dTime1 = std::chrono::high_resolution_clock::now();
            // auto dTime2 = std::chrono::high_resolution_clock::now();
            // double dt = 0;

            // do {
            //     ///

            //     for (size_t i = 0; i < dimension; ++i) {

            //         error[i] = setpoint[i] - robot_->currentAngle[actuator_id[i] - 1];

            //         integralError[i] += error[i];               // Accumulate the integral error
            //         if (dt > 0) { derivativeError[i] = (error[i] - previousError[i]) / dt;}

            //     }
                                     
            //     dTime2 = std::chrono::high_resolution_clock::now();
            //     std::chrono::duration<double> dt_ = dTime2 -dTime1;
            //     dt = dt_.count();


            //     for(size_t i =0; i< dimension; ++i){

            //     controlSignal[i] = proportionalGain * error[i] + integralGain * integralError[i] + derivativeGain * derivativeError[i];
            //     std::cout << "Signal " << i+1 << " " << controlSignal[i] << std::endl;
            //     if(error[i]<errorThreshold) controlSignal[i] = 0;
            //     robot_->actuateMotor(actuator_id[i], controlSignal[i]);

                
                 
            //     }


            //     for(size_t i =0; i< dimension; ++i){
                
            //     if(error[i]<errorThreshold) controlSignal[i] = 0;
            //     robot_->actuateMotor(actuator_id[i], controlSignal[i]);
            //     // std::this_thread::sleep_for(std::chrono::milliseconds(5));


            //     }



            //     previousError[0] = error[0];
            //     previousError[1] = error[1];

            //     dTime1 = dTime2;
                
               
            //     iteration++;

            //     robot_->showCurrentJoint();

            //     // Display Frequency
            //     if(iteration >20)
            //     {
            //         end_freq = std::chrono::high_resolution_clock::now();
            //         std::chrono::duration<double> duration = end_freq - start_freq;
            //         auto seconds =duration.count();
            //         std::cout << " Frequency : " << iteration/seconds <<  std::endl;
            //         iteration = 0;
            //         start_freq = std::chrono::high_resolution_clock::now();
            //     }
            // } while ((controlSignal[0]!=0)||(controlSignal[1]!=0));

            ////////////////////////////////////////////////////////

            for(int it =0 ; it < ROBOT_MEM_SIZE ; it++)
            {
                controlThreads_.emplace_back(&robot::robotPositionController::singleMotorControl,this,robot_->MotorList_[it],setpoint[it]);
            }
             std::cout << "Debug 5" << std::endl;


            for (auto& thread : controlThreads_){
                thread.join();
            }
            std::cout << "Debug 6" << std::endl;

            sleep(3);
            robot_->showCurrentJoint();

        }

    void robotPositionController::singleMotorControl(Motor motor, double setpoint){
            int iteration = 0;
            double controlSignal =0;

            // if(motor.motor_type == static_cast<std::string>("RMD")){
                
                PID_ERROR pid_error(0,0,0,0);
                Timer pid_timer;    
                pid_timer.start();
                pid_timer.stop();
                pid_timer.next_execution = std::chrono::steady_clock::now();
                double buf_error =0;

                do{ 
                    pid_timer.wait();

                    buf_error = setpoint - robot_->jointStates_[motor.motor_id-1];
                    pid_error.previousError_ = pid_error.error_;
                    pid_error.setError(buf_error ,buf_error, (buf_error - pid_error.previousError_)/pid_timer.dt_);

                    if(buf_error < errorThreshold){
                        iteration++;
                    }

                    controlSignal = proportionalGain * pid_error.error_ + integralGain * pid_error.integralError_ + derivativeGain * pid_error.derivativeError_;

                    signal[motor.motor_id-1] = controlSignal;
                    printf("Motor ID :%d , Posotion : %f,  Signal : %lf\n",motor.motor_id,robot_->jointStates_[motor.motor_id-1] ,controlSignal);

                }while((controlSignal !=0) && (std::abs(buf_error) > errorThreshold)&& (iteration > 200) );

            // }

        std::cout << "Single Motor" << motor.motor_id << "PID END" << std::endl;

    }

    void robotPositionController::PIDrun(){
        Timer timer;

        timer.next_execution = std::chrono::steady_clock::now();
        while(true){
            timer.wait();

            PID_SHM.SHM_WRITE(signal);
        }
    }

    void robotPositionController::robotrun(){
        robot_->run();
    }
    
        
}


