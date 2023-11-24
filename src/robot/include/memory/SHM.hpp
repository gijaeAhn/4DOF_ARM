#ifndef ROBOT_SHM
#define ROBOT_SHM
#pragma once
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>

#define  PID_CONTROL_KEY            1001
#define  GRAVITY_COMPENSATION_KEY   1002
#define  ANGLE_KEY                1003
#define  ROBOT_MEM_SIZE 2
#define MOTORINIT_TIME   5

namespace memory{



    template<typename T>
    class SHM
    {
        private:
        int SHM_id;
        int SHM_key;
        int SHM_size;
        int size_;

        public :

        SHM(int key, int size);

        void SHM_GETID();
        int SHM_CREATE();
        int SHM_WRITE(T* data);
        int SHM_READ(T* smeomry);
        void SHM_FREE();

    };

    template<typename T>
    SHM<T>::SHM(int key, int size) : SHM_key(key), SHM_size(sizeof(T)*size), size_(size)
    {}

    template<typename T>
    void SHM<T>::SHM_GETID(){
        if((SHM_id = shmget((key_t)SHM_key, 0, 0)) == -1)
        {
        perror("SHM_GETID : Failed to get SHM_ID");
        }
        printf("Success to get SHM_ID\n");

    }
    template<typename T>
    int SHM<T>::SHM_CREATE(){

        if((SHM_id = shmget((key_t)SHM_key, SHM_size, IPC_CREAT| IPC_EXCL | 0666)) == -1) {
        printf("SHM_CREATE : SHM already exist.\n");
        SHM_GETID();
        SHM_FREE();
        SHM_id = shmget((key_t)SHM_key, SHM_size, IPC_CREAT| 0666);
        
        if(SHM_id == -1)
        {
            perror("SHM_CREATE : SHM create fail");
            return 1;
        }
        else
        {
            SHM_FREE();
            SHM_id = shmget((key_t)SHM_key, ROBOT_MEM_SIZE, IPC_CREAT| 0666);
            
            if(SHM_id == -1)
            {
                perror("SHM_CREATE : SHM create fail");
                return 1;
            }
        }
    }
    
    return 0;

    }

    template<typename T>
    int SHM<T>::SHM_WRITE(T* data)
    {
        void *SHMaddr;
        if(sizeof(data)>SHM_size)
        {
            perror("SHM_WRITE : Size over");
            return 1;
        }
        if((SHMaddr = shmat(SHM_id, (void *)0, 0)) == (void *)-1) 
        {
            perror("SHM_WRITE : Shmat failed");
            return 1;
        }
        memcpy((float *)SHMaddr, data, SHM_size);
        if(shmdt(SHMaddr) == -1) 
        {
            perror("SHM_WRITE : Shmdt failed");
            return 1;
        }
    return 0;

    }


    template<typename T>
    int SHM<T>::SHM_READ(T* smemory)
    {
        void *SHMaddr;
        T mess[size_] = {0};
        
        if((SHMaddr = shmat(SHM_id, (void *)0, 0)) == (void *)-1)
        {
            perror("SHM_READ : Shmat failed");
            return 1;
        }
        
        memcpy(smemory, (T *)SHMaddr, sizeof(smemory));
        
        if(shmdt(SHMaddr) == -1)
        {
            perror("SHM_READ : Shmdt failed");
            return 1;
        }
    return 0;

    }
    
    template<typename T>
    void SHM<T>::SHM_FREE()
    {   
        SHM_GETID();
        if (SHM_id < 0) {
        std::cout << "SHM_FREE: Invalid SHM_id, cannot free memory." << std::endl;
        return;
        }
        if(shmctl(SHM_id, IPC_RMID, nullptr) == -1) 
        {
            perror("SHM_FREE : Shmctl failed");
            return ;
        }
    
    std::cout << "Shared memory (ID: " << SHM_id << ") successfully freed." << std::endl;

        return ;
    }


}

#endif