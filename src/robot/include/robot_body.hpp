#ifndef ROBOT_BODY
#define ROBOT_BODY

#pragma
#include "stuffs/motor.hpp"
#include "stuffs/timer.hpp"
#include "memory/SHM.hpp"

#include "FSM.hpp"
#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/motorInfo.hpp"

#include <unistd.h>
#include <vector>
#include <utility>


namespace robot {

using JointStates = std::vector<double>;
using MotorList = std::vector<Motor>;





    class Robot {
        friend class robotPositionController;
        protected :
        
        JointStates jointPosition_;
        MotorList MotorList_;
        fsm::FSM fsm_;
        myactuator_rmd::Driver* driver_;
        memory::SHM<float> robot_SHM;
        float smemory[ROBOT_MEM_SIZE];
        Timer timer;


        

      
        


        public :

        Robot();
        Robot(Robot&& other) noexcept;       


        void showCurrentJoint(); 
        void setJoint(std::vector<double> joint);
        void setMotor(Motor motor);
        void getJoint();
        void run();

    };

}


#endif