
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include <pthread.h>
#include <thread>
#include <utility>


#include "robot_body.hpp"
#include "robot_builder.hpp"
#include "robot_positionController.hpp"




int main()
{
    std::string ifname = "can0";
    myactuator_rmd::Driver driver(ifname);
    std::vector<int> motor = {1,2};
    robot::RobotBuilder test_builder;
    

    robot::Robot test_robot(test_builder.buildJoint(motor)
                              .buildSystem(&driver)
                              .build());


    robot::robotPositionController test_posControl(0.001,0.0001,0.000, &test_robot);

    std::vector<double> setpoint = {180,180};
    test_posControl.PIDcontrol(motor, setpoint,10000);
    

}