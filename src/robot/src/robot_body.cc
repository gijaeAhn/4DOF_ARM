#include "robot_body.hpp"
#include "stuffs/motor.hpp"





namespace robot {



Robot::Robot()
    : ANGLE_SHM(ANGLE_KEY, ROBOT_MEM_SIZE),
      VEL_SHM(VEL_KEY,ROBOT_MEM_SIZE)
    {
        ANGLE_SHM.SHM_GETID();
        VEL_SHM.SHM_GETID();
        for(int i = 0; i< ROBOT_MEM_SIZE; i++)
        {
            Amemory[i] = 0;
            Vmemory[i] = 0;
        }
        jointPosition_.resize(ROBOT_MEM_SIZE);
        jointVelocity_.resize(ROBOT_MEM_SIZE);
    }   

Robot::Robot(Robot&& other) noexcept 
    : driver_(std::exchange(other.driver_, nullptr)),
      fsm_(std::move(other.fsm_)),
      MotorList_(std::move(other.MotorList_)),
      ANGLE_SHM(ANGLE_KEY, ROBOT_MEM_SIZE),
      VEL_SHM(VEL_KEY,ROBOT_MEM_SIZE)
{
    ANGLE_SHM.SHM_GETID();
    VEL_SHM.SHM_GETID();
    for(int i = 0; i< ROBOT_MEM_SIZE; i++)
    {
        Amemory[i] = 0;
        Vmemory[i] = 0;
    }
    jointPosition_.resize(ROBOT_MEM_SIZE);
    jointVelocity_.resize(ROBOT_MEM_SIZE);
    
}

void Robot::showCurrentJoint(){
    printf("\033[0;31m");
    printf(" Current Joint Angle :");
    for(auto joint : jointPosition_){
        printf("%f ",joint );
    }
    printf("\n");
    printf("\033[0m");
}

void Robot::showCurrentJointV(){
    printf("\033[0;32m");
    printf(" Current Joint Angle :");
    for(auto joint : jointVelocity_){
        printf("%f ",joint );
    }
    printf("\n");
    printf("\033[0m");
}





void Robot::setMotor(Motor motor){
    MotorList_.push_back(motor);
    motorConstant_.push_back(motor.motorConstant);
}

void Robot::setJoint(std::vector<float> position){
    for (int i = 0; i < ROBOT_MEM_SIZE; i++) {
        Amemory[i] = position[i];
    }
    printf("%f %f %f ", Amemory[0], Amemory[1], Amemory[2]);
    ANGLE_SHM.SHM_WRITE(Amemory);


}

void Robot::getJoint(){


    ANGLE_SHM.SHM_READ(Amemory);


    for (int i =0; i< ROBOT_MEM_SIZE; i++)
    {
        jointPosition_[i] = Amemory[i];
    }
}

void Robot::getJointV(){
    VEL_SHM.SHM_READ(Vmemory);

    for (int i = 0; i <ROBOT_MEM_SIZE; i++)
    {
        jointVelocity_[i] = Vmemory[i];
    }
}


void Robot::run(){
    Timer timer;
    timer.next_execution = std::chrono::steady_clock::now();
    while(true){
        timer.wait();
        getJoint();
        getJointV();
        showCurrentJoint();
        showCurrentJointV();
    }

}
}