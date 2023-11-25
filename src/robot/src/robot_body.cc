#include "robot_body.hpp"
#include "stuffs/motor.hpp"





namespace robot {



Robot::Robot()
    :robot_SHM(ANGLE_KEY,ROBOT_MEM_SIZE)
    {
        robot_SHM.SHM_GETID();
        for(int i = 0; i< ROBOT_MEM_SIZE; i++)
        {
            smemory[i] = 0; 
        }
        jointPosition_.resize(ROBOT_MEM_SIZE);
    }   

Robot::Robot(Robot&& other) noexcept 
    :driver_(std::exchange(other.driver_, nullptr)),
     fsm_(std::move(other.fsm_)),
     MotorList_(std::move(other.MotorList_)),
     robot_SHM(ANGLE_KEY,ROBOT_MEM_SIZE)
{
    robot_SHM.SHM_GETID();
    for(int i = 0; i< ROBOT_MEM_SIZE; i++)
    {
        smemory[i] = 0; 
    }
    jointPosition_.resize(ROBOT_MEM_SIZE);
    
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



void Robot::setJoint(JointStates joint)
    {jointPosition_ = joint;}

void Robot::setMotor(Motor motor){
    MotorList_.push_back(motor);
}

void Robot::getJoint(){


    robot_SHM.SHM_READ(smemory);


    for (int i =0; i< ROBOT_MEM_SIZE; i++)
    {
        jointPosition_[i] = smemory[i];
    }
}

void Robot::run(){
    Timer timer;
    timer.next_execution = std::chrono::steady_clock::now();
    while(true){
    timer.wait();


    getJoint();


    }

}
}