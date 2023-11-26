#include "myactuator_rmd/driver.hpp"
#include "robot_body.hpp"
#include <vector>
#include <utility>


namespace robot {
    class RobotBuilder
    {
        private:
        Robot robot_;

        public:
        RobotBuilder();

        RobotBuilder& buildJoint(Motor motor);
        // RobotBuilder& buildSystem(myactuator_rmd::Driver* driver);
        Robot build();   
    
    };

}