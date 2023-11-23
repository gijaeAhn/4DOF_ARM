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
        SHM() = delete;
        SHM(SHM other) = delete;

        int SHM_INIT();
        int SHM_CREATE();
        int SHM_WRITE(T* data);
        int SHM_READ(T* smeomry);
        int SHM_FREE();

    };

    template<typename T>
    SHM<T>::SHM(int key, int size) : SHM_key(key), SHM_size(sizeof(T)*size), size_(size)
    {}

    template<typename T>
    int SHM<T>::SHM_INIT(){
        if((shmid = shmget((key_t)SHM_key, 0, 0)) == -1)
    {
        perror("SHM_INIT : Failed to get SHM_ID");
    }

    }
    template<typename T>
    int SHM<T>::SHM_CREATE(){

        if((SHM_id = shmget((key_t)SHM_key, SHM_size, IPC_CREAT| IPC_EXCL | 0666)) == -1) {
        printf("SHM_CREATE : SHM already exist.");
        
        SHM_id = shmget((key_t)SHM_key, SHM_size, IPC_CREAT| 0666);
        
        if(SHM_id == -1)
        {
            perror("SHM_CREATE : SHM create fail");
            return 1;
        }
        else
        {
            SharedMemoryFree();
            shmid = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT| 0666);
            
            if(shmid == -1)
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
        
        if(shmdt(shmaddr) == -1)
        {
            perror("SHM_READ : Shmdt failed");
            return 1;
        }
    return 0;

    }
    
    template<typename T>
    int SHM<T>::SHM_FREE()
    {
        if(shmctl(SHM_id, IPC_RMID, 0) == -1) 
        {
            perror("SHM_FREE : Shmctl failed");
            return 1;
        }
    
        printf("Destruct SHM");
        return 0;
    }


}