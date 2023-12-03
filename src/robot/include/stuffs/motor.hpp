#ifndef ROBOT_MOTOR
#define ROBOT_MOTOR
#pragma once

#include <cstdint>
#include <string>

namespace robot {


struct Motor {
    std::string motor_type; 
    int motor_id;
    int motorConstant;

    
    Motor(const std::string& type, int id, int motorconstant) : motor_type(type), motor_id(id), motorConstant(motorconstant) {}

    // Default Constructor
    Motor() : motor_type(""), motor_id(-1) {}
};

} // namespace robot

#endif // ROBOT_MOTOR