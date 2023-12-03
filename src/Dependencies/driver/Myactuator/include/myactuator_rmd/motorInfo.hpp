#ifndef MYACTUATOR_RMD__MOTOR_INFO
#define MYACTUATOR_RMD__MOTOR_INFO
#pragma once

#include <cstdint>

namespace myactuator_rmd{

const int oneShaftCycle = 40;
const int maxShaftAngle = 65535;
const int gearRatio = 9;
const float max_current = 3.125;


const int X8_CONST     = 51;
const int X8_V2_CONST  = 45;
const int X6_CONST     = 75;

const int X8_SHAFTCYCLE    = 51;
const int X8_V2_SHAFTCYCLE  = 45;
const int X6_SHAFTCYCLE     = 75;

const int X8_GEAR     = 51;
const int X8_V2_GEAR  = 45;
const int X6_GEAR     = 75;




}






#endif