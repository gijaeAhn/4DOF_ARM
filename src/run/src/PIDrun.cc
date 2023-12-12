
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
#include "controller/robot_gravityComensation.hpp"




int main()
{

    robot::Motor motor1{"RMD",1,myactuator_rmd::X8_CONST};
    robot::Motor motor2{"RMD",2,myactuator_rmd::X8_CONST};
    robot::Motor motor3{"RMD",3,myactuator_rmd::X6_CONST};

    //Build Robot
    robot::RobotBuilder test_builder;
    robot::Robot test_robot(test_builder
                              .buildJoint(motor1)
                              .buildJoint(motor2)
                              .buildJoint(motor3)
                              .build());
    //Setting Init Condition
    robot::robotPositionController test_posControl(4,0,0.4, &test_robot);
//    robot::robotPositionController test_posControl(0,0,0, &test_robot);
    robot::robotGravityCompensation test_grav(&test_robot);
    std::vector<float> init_pose = {0,-84.875443,-159.401627};

    test_robot.setJoint(init_pose);
    test_posControl.setpoint_ = init_pose;


    //Run Threads
    std::thread robotrun(&robot::Robot::run,&test_robot);
    std::thread PIDrun(&robot::robotPositionController::PIDrun,&test_posControl);
    std::thread GRAVrun(&robot::robotGravityCompensation::GCOMPrun,&test_grav);

    sleep(MOTORINIT_TIME);


//     Control Position
    test_posControl.PIDcontrol();







    robotrun.join();
    PIDrun.join();
    GRAVrun.join();


}