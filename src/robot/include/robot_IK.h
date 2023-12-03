//
// Created by sj on 23. 11. 28.
//
#ifndef ROBOT_IK_H
#define ROBOT_IK_H

#include <vector>
#include <stdio.h>
#include <cmath>
#include <Eigen/Dense>
#include "robot_COMMON.h"



namespace robot {

    std::vector<double> IK_SOLVER(Eigen::Matrix4d Trans, double prev_theta4){

        Eigen::Vector3d xyz;
        xyz(0) = Trans(0,3);
        double x = Trans(0,3);
        xyz(1) = Trans(1,3);
        double y = Trans(1,3);
        xyz(2) = Trans(2,3);
        double z = Trans(2,3);



        auto theta1 = ::atan2(y,x);
        auto theta3 = ((::pow(x, 2) + ::pow(y, 2) + ::pow(z, 2) - ::pow(L2, 2) - ::pow(L3, 2) ) / (2 * L2 * L3);
        auto theta2 = ::acos((::pow(L2,2) - ::pow(L1,2) - ::pow(xyz.norm(),2))/(2*L1*xyz.norm()));

        std::vector<double> solution = {theta1,theta2, theta3,prev_theta4};

        return solution;

    };
}
#endif //ROBOT_IK_H



