
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
    robot::robotPositionController test_posControl(0.0015,0.0000001,0.000001, &test_robot);


    

    //Run Threads
    std::thread robotrun(&robot::Robot::run,&test_robot);
    std::thread PIDrun(&robot::robotPositionController::PIDrun,&test_posControl);
    
    std::cout << "Debug 2" << std::endl;

    std::cout << "Debug 3" << std::endl;

    

    sleep(MOTORINIT_TIME);
    sleep(MOTORINIT_TIME);

    //Control Position
    std::vector<double> setpoint = {180,180};
    test_posControl.PIDcontrol(setpoint);

        std::cout << "Debug 4" << std::endl;

    robotrun.join();
    PIDrun.join();
    

}