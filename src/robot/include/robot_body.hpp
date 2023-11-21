#ifndef ROBOT_BODY
#define ROBOT_BODY

#pragma


#include "FSM.hpp"
#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/motorInfo.hpp"

#include <unistd.h>
#include <vector>
#include <utility>


namespace robot {

using JointStates = std::vector<double>;
using MotorList = std::vector<double>;





    class Robot {
        friend class robotPositionController;
        protected :
        
        JointStates jointStates_;
        fsm::FSM fsm_;
        
        
        
        std::vector<int> MotorList;

        std::vector<int> previousShaftAngle;
        std::vector<double> currentAngle;
        

        myactuator_rmd::Driver* driver_;

        

      
        


        public :

        Robot();
        Robot(Robot&& other) noexcept;       
        void addMotor(std::uint32_t actuator_id);
        void showCurrentState();
        void showCurrentJoint(); 
        void setJoint(std::vector<double> joint);
        void setMotor(std::vector<int> motor);
        void setDriver(myactuator_rmd::Driver* driver);

        void updateMotorPosition(std::uint32_t actuator_id, myactuator_rmd::Feedback feedback);
      
        void calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle);

        void actuateMotor(std::uint32_t actuator_id,float controlSignal);
    };

}


#endif