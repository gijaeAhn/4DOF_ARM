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

    typedef struct Jointstate {


        double position;
        double velocity;
    }Jointstate;


using JointStates = std::vector<Jointstate>;
using MotorList = std::vector<Motor>;





    class Robot {
        friend class robotPositionController;
        friend class robotGravityCompensation;
        protected :
        
        std::vector<double> jointPosition_;
        std::vector<double> jointVelocity_;
        std::vector<double> motorConstant_;
        MotorList motorList;
        fsm::FSM fsm_;
        myactuator_rmd::Driver* driver_;
        memory::SHM<float> ANGLE_SHM;
        memory::SHM<float> VEL_SHM;
        float Amemory[ROBOT_MEM_SIZE];
        float Vmemory[ROBOT_MEM_SIZE];



        public :

        Robot();
        Robot(Robot&& other) noexcept;       


        void showCurrentJoint();
        void showCurrentJointV();
        void setMotor(Motor motor);
        void setJoint(std::vector<float> position);
        void getJoint();
        void getJointV();
        void run();

    };

}


#endif