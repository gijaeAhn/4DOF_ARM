#include "controller/robot_gravityComensation.hpp"

namespace robot{

    robotGravityCompensation::robotGravityCompensation(robot::Robot *robot)
    : GRAV_SHM(GRAVITY_COMPENSATION_KEY,ROBOT_MEM_SIZE),
      ANGLE_SHM(ANGLE_KEY, ROBOT_MEM_SIZE),
      robot_(robot)

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
        signal[1] = 2.4 * ::sin(angle[1]*DEGREE_2_RADIAN) + 1.3 * ::sin((angle[1] - angle[2])*DEGREE_2_RADIAN);
        signal[2] = 1.27838156 * ::sin((angle[1] - angle[2])*DEGREE_2_RADIAN);

        if(angle[1] > 15.0){
            real_siganl[0] = 0;
            real_siganl[1] =   -(signal[1] / 2.0);
            real_siganl[2] = signal[2] / 1.35;
        }
        else if(angle[1]> 30.0){
            real_siganl[0] = 0;
            real_siganl[1] =   -(signal[1] / 1.9);
            real_siganl[2] = signal[2] / 1.35;
        }
        else if(angle[1]  > 40 ){
            real_siganl[0] = 0;
            real_siganl[1] =   -(signal[1] / 2.1);
            real_siganl[2] = signal[2] / 1.35;
        }
        else if(angle[1] > 58)
        {
            real_siganl[0] = 0;
            real_siganl[1] =   -(signal[1] / 2.2);
            real_siganl[2] = signal[2] / 1.35;
        }
        else if(angle[1] > 86)
        {
            real_siganl[0] = 0;
            real_siganl[1] =   -(signal[1] / 2.4);
            real_siganl[2] = signal[2] / 1.35;
        }
        else{
            real_siganl[0]= 0;
            real_siganl[1] =   -(signal[1] / 1.9);
            real_siganl[2] = signal[2] / 1.35;
        }

//        printf(" Gravity Comp : [2 Joint]%f [3 Joint]%f\n", real_siganl[1], real_siganl[2]);
    }

    void robotGravityCompensation::GCOMPrun() {
        Timer timer;

        timer.next_execution = std::chrono::steady_clock::now();
        while (true) {
            timer.wait();
            calcGComp();
            GRAV_SHM.SHM_WRITE(real_siganl);
        }
    }














}