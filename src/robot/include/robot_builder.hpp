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

        RobotBuilder& buildJoint(std::vector<uint32_t> motor);
        RobotBuilder& buildSystem(myactuator_rmd::Driver* driver);
        Robot build();   
    
    };

}