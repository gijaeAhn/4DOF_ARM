#include "myactuator_rmd/driver.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include "myactuator_rmd/positioncontrol.hpp"
#include <pthread.h>
#include <thread>








int main()
{
    std::string if_name = "can0";

    myactuator_rmd::MotorPositionController test_controller(0.0001,0.0001, 0.000,if_name);
    std::cout << "Motor Running" << std::endl;

    test_controller.addMotor(1);
    test_controller.addMotor(2);

    std::vector<std::uint32_t> id_list;
    id_list.push_back(1);
    id_list.push_back(2);
    std::vector<double> set_point_list;
    set_point_list.push_back(180);
    set_point_list.push_back(180);

    // std::thread _thread1([&]() { test_controller.PIDcontrol(1, 180,10000); });
    // std::thread _thread2([&]() { test_controller.PIDcontrol(2, 180,10000); });
    test_controller.PIDcontrol(id_list,set_point_list,10000);

    // _thread1.join();
    // _thread2.join();

}