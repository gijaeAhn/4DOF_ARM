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
    memory::SHM<float> GRAV_SHM;
    memory::SHM<float> ANGLE_SHM;
    float signal[ROBOT_MEM_SIZE];
    float angle[ROBOT_MEM_SIZE];
    float real_siganl[ROBOT_MEM_SIZE];

    public:

        robotGravityCompensation(Robot* robot);

        ~robotGravityCompensation();

        void calcGComp();

        void GCOMPrun();


};







}



