#include "robot_body.hpp"
#include "stuffs/motor.hpp"





namespace robot {



Robot::Robot(){};

Robot::Robot(Robot&& other) noexcept 
    :driver_(std::exchange(other.driver_, nullptr)),
     fsm_(std::move(other.fsm_)),
     previousShaftAngle(std::move(other.previousShaftAngle)),
     currentAngle(std::move(other.currentAngle)),
     MotorList_(std::move(other.MotorList_))
{

}

void Robot::showCurrentJoint(){
    printf("\033[0;31m");
    printf(" Current Joint Angle :");
    for(auto joint : currentAngle){
        printf("%f ",joint );
    }
    printf("\n");
    printf("\033[0m");
}

void Robot::addMotorR(Motor motor){

    driver_->addMotor(motor.motor_id);    
    driver_->MotorRunning(motor.motor_id);
    std::cout << "Motor set" << std::endl;
    myactuator_rmd::Feedback buf {driver_->sendTorqueSetpoint(motor.motor_id,0)};
    std::cout << "Motor torque 0 set" << std::endl;
    previousShaftAngle.push_back(buf.shaft_angle);
    currentAngle.push_back(0);
    std::cout << currentAngle.size() << std::endl;
    sleep(3);
    }

void Robot::setJoint(std::vector<double> joint)
    {currentAngle = joint;}

void Robot::setMotor(Motor motor){
    MotorList_.push_back(motor);
    addMotorR(motor);
    std::cout << "Debug 5" << std::endl;

}

void Robot::setDriver(myactuator_rmd::Driver* driver)
    {driver_ = driver;}



void Robot::updateJointPosition(int jointNum, myactuator_rmd::Feedback feedback) 
        {
            int currentShaftAngle = feedback.shaft_angle;
            calculateCurrentAngle(jointNum, currentShaftAngle);
            previousShaftAngle[jointNum -1] = currentShaftAngle;
  
        }

void Robot::calculateCurrentAngle(int jointNum, int currentShaftAngle)
        {    

            float shaftChange =0;
            if (currentShaftAngle - previousShaftAngle[jointNum-1] > 40000) {
                shaftChange = -((myactuator_rmd::maxShaftAngle - currentShaftAngle) + previousShaftAngle[jointNum-1]);
            }
            if (currentShaftAngle - previousShaftAngle[jointNum-1] < -40000) {
                shaftChange = currentShaftAngle + (myactuator_rmd::maxShaftAngle - previousShaftAngle[jointNum-1]);
            }
            else
            {
                shaftChange = currentShaftAngle - previousShaftAngle[jointNum-1];
            }

            currentAngle[jointNum-1] += shaftChange/myactuator_rmd::maxShaftAngle*myactuator_rmd::oneShaftCycle;

        }

void Robot::actuateMotor(int jointNum, float controlSignal) 
        {   
            myactuator_rmd::Feedback buf;
            // Clamping controlSignal to the range of -20.0 to 20.0
            float clampedSignal = std::max(-20.0f, std::min(controlSignal, 20.0f));
            buf = driver_->sendTorqueSetpoint(jointNum, clampedSignal);
            updateJointPosition(jointNum,buf);
        }



}