#include "FSM_body.hpp"
#include "robot_builder.hpp"
#include "robot_positionController.hpp"
#include "robot_run.hpp"
#include "robot_state.hpp"

#include <vector>

namespace robot {

using JointStates = std::vector<double>;
using MotorList = std::vector<double>;





    class Robot {

        protected :
        
        JointStates jointStates_;
        fsm::FSM fsm_;
        MotorList motorList_;
        myactuator_rmd::Driver* driver_;
        
        

        

        robotPositionController Pcontroller_;


        void robotInit();
        void setJoint(std::vector<double> joint);
        void setMotor(std::vector<int> motor);
        void setDriver(myactuator_rmd::Driver &driver);


        public :
        
        void showCurrentState();
        void showCurrentJoint(); 
        void movePosition(std::vector<double> position);
        void activateImpedence();

    }
}