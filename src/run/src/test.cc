
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
    std::vector<std::uint32_t> motor = {1,2};
    robot::RobotBuilder test_builder;
    std::vector<std::uint32_t> motor_id = {1,2};

    robot::Robot test_robot(test_builder
                              .buildSystem(&driver)
                              .buildJoint(motor)
                              .build());



    robot::robotPositionController test_posControl(0.000001,0.00005,-0.00001, &test_robot);



    std::vector<double> setpoint = {180,180};
    test_posControl.PIDcontrol(motor_id, setpoint,10000);
    

}