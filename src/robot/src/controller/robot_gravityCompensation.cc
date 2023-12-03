#include "controller/robot_gravityComensation.hpp"

namespace robot{

    robotGravityCompensation::robotGravityCompensation(robot::Robot *robot)
    : GRAV_SHM(GRAVITY_COMPENSATION_KEY,ROBOT_MEM_SIZE),
      ANGLE_SHM(ANGLE_KEY, ROBOT_MEM_SIZE)
    {
        ANGLE_SHM.SHM_GETID();
        GRAV_SHM.SHM_GETID();

        for( int i = 0; i < ROBOT_MEM_SIZE; i++)
        {
            signal[i] = 0;
        }

    }

    robotGravityCompensation::~robotGravityCompensation()
    {}


    void robotGravityCompensation::calcGComp()
    {
        ANGLE_SHM.SHM_READ(angle);
        signal[1] = MASS1 * G_CONSTANT * L2 *  ::sin(angle[1] * DEGREE_2_RADIAN)
                  - MASS2 * G_CONSTANT * L3 * (::cos(angle[1] * DEGREE_2_RADIAN) + ::cos(angle[1] + angle[2]));
        signal[2] = MASS2 * G_CONSTANT * L3 *  ::sin(angle[2]);

        real_siganl[1] = signal[1] / robot_->MotorList_[1].motorConstant;
        real_siganl[2] = signal[2] / robot_->MotorList_[2].motorConstant;
    }

    void robotGravityCompensation::GCOMPrun() {
        Timer timer;

        timer.next_execution = std::chrono::steady_clock::now();
        while (true) {
            timer.wait();
            GRAV_SHM.SHM_WRITE(real_siganl);
        }
    }














}