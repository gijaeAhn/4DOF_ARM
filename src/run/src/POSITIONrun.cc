//
// Created by GJ on 23. 12. 12.
//

#include "memory/SHM.hpp"
#include <vector>
#include <iostream>
#include <csignal>
#include <algorithm>

memory::SHM<float> setPOSITION_SHM(POSITION_SET_KEY,ROBOT_MEM_SIZE);

void signalHandler(int signum);

int main(){

    signal(SIGINT, signalHandler);
    float position_set_buffer[ROBOT_MEM_SIZE] = {0,0,0};
    setPOSITION_SHM.SHM_CREATE();


    while(true)
    {
        printf("Position : %f %f %f\n", position_set_buffer[0], position_set_buffer[1], position_set_buffer[2]);
        position_set_buffer[0] = 0;
        position_set_buffer[1] = 0;
        position_set_buffer[2] = -90;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);

        sleep(2);
        printf("Position : %f %f %f\n", position_set_buffer[0], position_set_buffer[1], position_set_buffer[2]);

        position_set_buffer[0] = 30;
        position_set_buffer[1] = 0;
        position_set_buffer[2] = -90;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);

        sleep(2);
        printf("Position : %f %f %f\n", position_set_buffer[0], position_set_buffer[1], position_set_buffer[2]);

        position_set_buffer[0] = 30;
        position_set_buffer[1] = 30;
        position_set_buffer[2] = -60;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);
        sleep(2);printf("Position : %f %f %f\n", position_set_buffer[0], position_set_buffer[1], position_set_buffer[2]);

        position_set_buffer[0] = 30;
        position_set_buffer[1] = 0;
        position_set_buffer[2] = -90;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);
        sleep(2);printf("Position : %f %f %f\n", position_set_buffer[0], position_set_buffer[1], position_set_buffer[2]);

        position_set_buffer[0] = -30;
        position_set_buffer[1] = 0;
        position_set_buffer[2] = -90;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);
        sleep(2);


        position_set_buffer[0] = -30;
        position_set_buffer[1] = 30;
        position_set_buffer[2] = -60;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);
        sleep(2);


        position_set_buffer[0] = -30;
        position_set_buffer[1] = 0;
        position_set_buffer[2] = -90;
        setPOSITION_SHM.SHM_WRITE(position_set_buffer);
        sleep(2);
    }
}

void signalHandler(int signum) {
    printf("Interrupt siganl (%d) recived\n", signum);
    setPOSITION_SHM.SHM_FREE();
    exit(EXIT_SUCCESS);
}