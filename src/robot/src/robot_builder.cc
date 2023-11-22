#ifndef ROBOT_BUILDER
#define ROBOT_BUILDER



#include "robot_builder.hpp"


namespace robot {


RobotBuilder::RobotBuilder(){}

RobotBuilder& RobotBuilder::buildJoint(std::vector<int> motor){
    robot_.setMotor(motor);
    return *this;
}

RobotBuilder& RobotBuilder::buildSystem(myactuator_rmd::Driver* driver){
    robot_.setDriver(driver);
    return *this;
}

Robot RobotBuilder::build(){
    return std::move(robot_);
}
}

#endif