
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include <pthread.h>
#include <thread>
#include <utility>


#include "robot_body.hpp"
#include "robot_builder.hpp"
#include "stuffs/motor.hpp"
#include "controller/robot_positionController.hpp"





int main()
{

    robot::Motor motor1{"RMD",1};
    robot::Motor motor2{"RMD",2};


    robot::RobotBuilder test_builder;


    robot::Robot test_robot(test_builder
                              .buildJoint(motor1)
                              .buildJoint(motor2)
                              .build());



    robot::robotPositionController test_posControl(0.000001,0.00005,-0.00001, &test_robot);
    test_posControl.run();



    std::vector<double> setpoint = {180,180};
    test_posControl.PIDcontrol(setpoint);
    

}