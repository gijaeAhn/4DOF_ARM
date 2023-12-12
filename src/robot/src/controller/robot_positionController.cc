#include "controller/robot_positionController.hpp"
#define DEGREE_2_RADIAN 0.0174532925




namespace robot{


        robotPositionController::robotPositionController(float pGain, float iGain,float dGain,Robot* robot) 
        :  proportionalGain(pGain),  derivativeGain(dGain),integralGain(iGain), robot_(robot), PID_SHM(PID_CONTROL_KEY,ROBOT_MEM_SIZE),
           POSITION_SET_SHM(POSITION_SET_KEY,ROBOT_MEM_SIZE)
        {
            PID_SHM.SHM_GETID();
            POSITION_SET_SHM.SHM_GETID();
            for ( int i =0; i <ROBOT_MEM_SIZE; i++){
                signal[i] =0;
            }
            setpoint_.resize(ROBOT_MEM_SIZE);
        }

        robotPositionController::~robotPositionController()
        {}

        



        void robotPositionController::PIDcontrol()
        {

            std::cout<<"PID CONTROL" << std::endl;

            for(int i = 0; i < ROBOT_MEM_SIZE; i++){
                real_signal[i] = 0;
            }


            ////////////////////////////////////////////////////////

            for(int it =0 ; it < ROBOT_MEM_SIZE ; it++)
            {
                controlThreads_.emplace_back(&robot::robotPositionController::singleMotorControl, this, robot_->motorList[it]);
            }

            for (auto& thread : controlThreads_){
                thread.join();
            }

        }

    void robotPositionController::singleMotorControl(Motor motor){

            printf("Debug2");

            // RMD MOTOR PID CONTROL
            if(motor.motor_type == static_cast<std::string>("RMD")){
                printf("Debug1");
                int iteration = 0;
                double controlSignal =0;
                double error = 0;

                PID_ERROR pid_error(0,0,0,0);
                Timer pid_timer;    
                pid_timer.start();
                pid_timer.stop();
                pid_timer.next_execution = std::chrono::steady_clock::now();


                do{ 
                    pid_timer.wait();
                    double currentPosition = robot_->jointPosition_[motor.motor_id - 1];

                    error = (setpoint_[motor.motor_id-1] - currentPosition) * DEGREE_2_RADIAN;
                    double ivalue = pid_timer.dt_ * error; 
                    double deriva = (error - pid_error.error_) / pid_timer.dt_; 
                    pid_error.setError(error, ivalue, deriva);

                    controlSignal = static_cast<float>(
                                    proportionalGain *      pid_error.error_ +
//                                    integralGain     *      pid_error.integralError_ +
                                    derivativeGain   *      pid_error.derivativeError_);

                                   

                    signal[motor.motor_id-1] = controlSignal;
                    real_signal[motor.motor_id-1] = controlSignal/200.0;
                    if(motor.motor_id ==3) real_signal[motor.motor_id-1] = real_signal[motor.motor_id-1] * 1.2;
                    printf("Setpoint : %f\n", setpoint_[motor.motor_id-1]);
                    printf(" Motor %d Debug joint position : %f \n", motor.motor_id,robot_->jointPosition_[motor.motor_id - 1] );
                    printf( "Motor ID : %d error : %f , contorlSignal : %f\n",motor.motor_id, error, real_signal[motor.motor_id-1] );

                    real_signal[motor.motor_id-1] = controlSignal;

                    iteration++;
                }while(true);

            }
            // RMD CONTROL PID END
            printf( " Motor %d, PID END", motor.motor_id);


    }

    void robotPositionController::PIDrun(){
        Timer timer;

        timer.next_execution = std::chrono::steady_clock::now();
        while(true){
            timer.wait();
            POSITION_SET_SHM.SHM_READ(set_position);
            for(int iter =0; iter < ROBOT_MEM_SIZE; iter++){
                printf(" Recieved set position %f %f %f\n" ,set_position[0],set_position[1],set_position[2]);
            }
            for(int iter =0; iter < ROBOT_MEM_SIZE; iter++){
                setpoint_[iter] = set_position[iter];
            }
            PID_SHM.SHM_WRITE(real_signal);
        }
    }

    
        
}



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

//         error[i] = setpoint_[i] - robot_->currentAngle[actuator_id[i] - 1];

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


