#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/motorInfo.hpp"
#include "memory/SHM.hpp"
#include "stuffs/timer.hpp"

#include <utility>
#include <vector>
#include <iostream>
#include <csignal>




memory::SHM<float> getSHM_PID(PID_CONTROL_KEY,ROBOT_MEM_SIZE);
memory::SHM<float> getSHM_GRAV(GRAVITY_COMPENSATION_KEY,ROBOT_MEM_SIZE);
memory::SHM<float> setSHM_ANGLE(ANGLE_KEY,ROBOT_MEM_SIZE);



void signalHandler(int signum);


int main()
{
    signal(SIGINT, signalHandler);

memory::SHM<float> getSHM_PID(PID_CONTROL_KEY,ROBOT_MEM_SIZE);
memory::SHM<float> getSHM_GRAV(GRAVITY_COMPENSATION_KEY,ROBOT_MEM_SIZE);
memory::SHM<float> setSHM_ANGLE(ANGLE_KEY,ROBOT_MEM_SIZE);

    robot::Timer timer;
    timer.next_execution = std::chrono::steady_clock::now();
    myactuator_rmd::Driver driver("can0");

    std::vector<myactuator_rmd::Feedback> buf_feed;
    buf_feed.resize(ROBOT_MEM_SIZE);

    std::vector<int> currentShaft = {ROBOT_MEM_SIZE,0};
    std::vector<int> previousShaft = {ROBOT_MEM_SIZE,0};
    float pid_buffer[ROBOT_MEM_SIZE];
    float grav_buffer[ROBOT_MEM_SIZE];
    float sum_buffer[ROBOT_MEM_SIZE];
    float ang_buffer[ROBOT_MEM_SIZE];
    float shaftChange[ROBOT_MEM_SIZE];

 


    getSHM_PID.SHM_CREATE();
    getSHM_GRAV.SHM_CREATE();
    setSHM_ANGLE.SHM_CREATE();




    for(int i =0; i<ROBOT_MEM_SIZE ; i++)
    {
        driver.addMotor(i+1);
        driver.MotorRunning(i+1);
        myactuator_rmd::Feedback buf {driver.sendTorqueSetpoint(i+1,0)};
        previousShaft[i] = buf.shaft_angle;
        ang_buffer[i] =0;
        shaftChange[i] = 0;
        sleep(MOTORINIT_TIME);
    }
    int iteration = 0;
    setSHM_ANGLE.SHM_WRITE(ang_buffer);
    while(true){
        iteration ++;
        timer.wait();
        getSHM_PID.SHM_READ(pid_buffer);
        getSHM_PID.SHM_READ(grav_buffer);

        
            for(int iter =0; iter < ROBOT_MEM_SIZE; iter++)
            {   
                

                sum_buffer[iter] = std::max(-20.0f, std::min(pid_buffer[iter] , 20.0f));

                buf_feed[iter] = driver.sendTorqueSetpoint(iter+1,sum_buffer[iter]);
                currentShaft[iter] = buf_feed[iter].shaft_angle;
                if(iteration %300 ==0){
                printf("Motor 1 siganl : %f\n", pid_buffer[0]);
                printf("Motor 2 siganl : %f\n", pid_buffer[1]);

                printf("Current Shaft %d, : %lf \n", iter+1, currentShaft[iter]);

                }

                if (currentShaft[iter] - previousShaft[iter] > 50000) {
                    shaftChange[iter] = -((myactuator_rmd::maxShaftAngle - currentShaft[iter]) + previousShaft[iter]);
                }
                else if (currentShaft[iter] - previousShaft[iter] < -50000) {
                    shaftChange[iter] = currentShaft[iter] + (myactuator_rmd::maxShaftAngle - previousShaft[iter]);
                }
                else
                {
                    shaftChange[iter] = currentShaft[iter] - previousShaft[iter];
                }

                previousShaft[iter] = currentShaft[iter];

                ang_buffer[iter] += shaftChange[iter]/(myactuator_rmd::maxShaftAngle)*(myactuator_rmd::oneShaftCycle);
            }

        setSHM_ANGLE.SHM_WRITE(ang_buffer);

    }

    return 0;
    
}

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << " ) recieved.\n" << std::endl; 
    getSHM_PID.SHM_FREE();
    getSHM_GRAV.SHM_FREE();
    setSHM_ANGLE.SHM_FREE();
}
