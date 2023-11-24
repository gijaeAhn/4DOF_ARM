
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

    //Build Robot
    robot::RobotBuilder test_builder;
    robot::Robot test_robot(test_builder
                              .buildJoint(motor1)
                              .buildJoint(motor2)
                              .build());
    robot::robotPositionController test_posControl(0.000001,0.0000,0.00001, &test_robot);




    //Run Threads
    std::thread robotrun(&robot::Robot::run,&test_robot);
    std::thread PID_run(&robot::robotPositionController::PIDrun, &test_posControl);
    robotrun.join();
    PID_run.join();
    


    //Control Position
    std::vector<double> setpoint = {180,180};
    test_posControl.PIDcontrol(setpoint);
    

}