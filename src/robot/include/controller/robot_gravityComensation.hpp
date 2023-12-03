#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/motorInfo.hpp"

#include "robot_body.hpp"
#include "memory/SHM.hpp"


#include "stuffs/timer.hpp"
#include "stuffs/motor.hpp"

#include "robot_COMMON.h"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>
#include <cmath>



namespace robot {

class robotGravityCompensation{

    private:

    Robot* robot_;
    memory::SHM<double> GRAV_SHM;
    memory::SHM<double> ANGLE_SHM;
    double signal[ROBOT_MEM_SIZE];
    double angle[ROBOT_MEM_SIZE];
    double real_siganl[ROBOT_MEM_SIZE];

    public:

        robotGravityCompensation(Robot* robot);

        ~robotGravityCompensation();

        void calcGComp();

        void GCOMPrun();


};







}



