#include "FSM.hpp"
#include "robot_builder.hpp"


#include <vector>

namespace robot {

using JointStates = std::vector<double>;
using MotorList = std::vector<double>;





    class Robot {

        protected :
        
        JointStates jointStates_;
        fsm::FSM fsm_;
        
        
        
        std::vector<int> MotorList;

        std::vector<int> previousShaftAngle;
        std::vector<double> currentAngle;
        

        
        void addMotor(std::uint32_t actuator_id);

        void robotInit();
        


        public :

        myactuator_rmd::Driver* driver_;
        
        void showCurrentState();
        void showCurrentJoint(); 
        void movePosition(std::vector<double> position);
        void activateImpedence();
        void setJoint(std::vector<double> joint);
        void setMotor(std::vector<int> motor);
        void setDriver(myactuator_rmd::Driver &driver);
    }
};