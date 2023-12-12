#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/motorInfo.hpp"

#include "robot_body.hpp"
#include "memory/SHM.hpp"

#include "stuffs/pid_error.hpp"
#include "stuffs/timer.hpp"
#include "stuffs/motor.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>


namespace robot{

class robotPositionController {
    private :

        Robot* robot_;
        memory::SHM<float> PID_SHM;
        memory::SHM<float> POSITION_SET_SHM;
        float signal[ROBOT_MEM_SIZE];
        float real_signal[ROBOT_MEM_SIZE];
        float set_position[ROBOT_MEM_SIZE];
        std::vector<std::thread> controlThreads_;

        float proportionalGain;
        float integralGain;
        float derivativeGain;





    public:

        robotPositionController(float pGain, float iGain,float dGain,Robot* robot);

        ~robotPositionController();


        void PIDcontrol();

        void singleMotorControl(Motor motor);

        void PIDrun();

        std::vector<float> setpoint_;


        
};
}