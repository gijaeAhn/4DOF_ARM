#include "myactuator_rmd/driver.hpp"
#include "memory/SHM.hpp"
#include "stuffs/timer.hpp"


namespace robot{
template<typename T>
void do_SHM(memory::SHM<T> SHM){

}




int main()
{
    memory::SHM<float> getSHM_PID(PID_CONTROL_KEY,ROBOT_MEM_SIZE);
    memory::SHM<float> getSHM_GRAV(GRAVITY_COMPENSATION_KEY,ROBOT_MEM_SIZE);
    memory::SHM<float> setSHM_ANGLE(ANGLE_KEY,ROBOT_MEM_SIZE);
    robot::Timer timer;
    myactuator_rmd::Driver driver("can0");

    getSHM_PID.SHM_INIT();
    getSHM_PID.SHM_CREATE();

    getSHM_GRAV.SHM_INIT();
    getSHM_GRAV.SHM_CREATE();

    setSHM_ANGLE.SHM_INIT();
    setSHM_ANGLE.SHM_CREATE();


    float pid_buffer[ROBOT_MEM_SIZE];
    float grav_buffer[ROBOT_MEM_SIZE];
    float sum_buffer[ROBOT_MEM_SIZE];
    float ang_buffer[ROBOT_MEM_SIZE];


    while(true){

        getSHM_PID.SHM_READ(pid_buffer);
        getSHM_PID.SHM_READ(grav_buffer);
        
        for(int iter =0; iter < ROBOT_MEM_SIZE; iter++)
        {
            sum_buffer[iter] = pid_buffer[iter] + grav_buffer[iter];
        }





    }
    
    

}
}