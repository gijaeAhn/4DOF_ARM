#ifndef ROBOT_BUILDER
#define ROBOT_BUILDER



#include "robot_builder.hpp"
#include "stuffs/motor.hpp"


namespace robot {


RobotBuilder::RobotBuilder(){}

RobotBuilder& RobotBuilder::buildJoint(Motor motor){
    robot_.setMotor(motor);
    return *this;
}


Robot RobotBuilder::build(){
    return std::move(robot_);
}
}

#endif

// RobotBuilder& RobotBuilder::buildSystem(myactuator_rmd::Driver* driver){
//     robot_.setDriver(driver);
//     return *this;
// }