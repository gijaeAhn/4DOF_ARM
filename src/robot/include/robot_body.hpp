#ifndef ROBOT_BODY
#define ROBOT_BODY

#pragma
#include "stuffs/motor.hpp"

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
        
        JointStates jointStates_;
        fsm::FSM fsm_;
        
        
        
        MotorList MotorList_;

        std::vector<int> previousShaftAngle;
        std::vector<double> currentAngle;
        

        myactuator_rmd::Driver* driver_;

        

      
        


        public :

        Robot();
        Robot(Robot&& other) noexcept;       
        void addMotorR(Motor motor);
        void showCurrentState();
        void showCurrentJoint(); 
        void setJoint(std::vector<double> joint);
        void setMotor(Motor motor);
        void setDriver(myactuator_rmd::Driver* driver);

        void updateJointPosition(int jointNum, myactuator_rmd::Feedback feedback);
      
        void calculateCurrentAngle(int jointNum, int currentShaftAngle);

        void actuateMotor(int jointNum,float controlSignal);
    };

}


#endif