#include "robot_body.hpp"





namespace robot {



Robot::Robot(){};

Robot::Robot(Robot&& other) noexcept 
    :driver_(std::exchange(other.driver_, nullptr)),
     fsm_(std::move(other.fsm_)),
     previousShaftAngle(std::move(other.previousShaftAngle)),
     currentAngle(std::move(other.currentAngle)),
     MotorList(std::move(other.MotorList))
{

}

void Robot::addMotor(std::uint32_t actuator_id){
    driver_->addMotor(actuator_id);
    driver_->MotorRunning(actuator_id);
    std::cout << "Motor set" << std::endl;
    myactuator_rmd::Feedback buf {driver_->sendTorqueSetpoint(actuator_id,0)};
    std::cout << "Motor torque 0 set" << std::endl;
    previousShaftAngle.push_back(buf.shaft_angle);
    currentAngle.push_back(0);
    std::cout << currentAngle.size() << std::endl;
    sleep(5);
    }

void Robot::setJoint(std::vector<double> joint)
    {currentAngle = joint;}

void Robot::setMotor(std::vector<int> motor){
    MotorList = motor;
    for(int i =0; i<motor.size(); i++){
        addMotor(MotorList[i]);
    }
}

void Robot::setDriver(myactuator_rmd::Driver* driver)
    {driver_ = driver;}



void Robot::updateMotorPosition(std::uint32_t actuator_id, myactuator_rmd::Feedback feedback) 
        {
            int currentShaftAngle = feedback.shaft_angle;
            calculateCurrentAngle(actuator_id, currentShaftAngle);
            previousShaftAngle[actuator_id -1] = currentShaftAngle;
  
        }

void Robot::calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle)
        {    

            float shaftChange =0;
            if (currentShaftAngle - previousShaftAngle[actuator_id-1] > 40000) {
                // carry += (currentShaftAngle < previousShaftAngle) ? 1 : -1;
                shaftChange = -((myactuator_rmd::maxShaftAngle - currentShaftAngle) + previousShaftAngle[actuator_id-1]);
            }
            if (currentShaftAngle - previousShaftAngle[actuator_id-1] < -40000) {
                // carry += (currentShaftAngle < previousShaftAngle) ? 1 : -1;
                shaftChange = currentShaftAngle + (myactuator_rmd::maxShaftAngle - previousShaftAngle[actuator_id-1]);
            }
            else
            {
                shaftChange = currentShaftAngle - previousShaftAngle[actuator_id-1];
            }

            currentAngle[actuator_id-1] += shaftChange/myactuator_rmd::maxShaftAngle*myactuator_rmd::oneShaftCycle;

        }

void Robot::actuateMotor(std::uint32_t actuator_id, float controlSignal) 
        {   
            myactuator_rmd::Feedback buf;
            // Clamping controlSignal to the range of -20.0 to 20.0
            float clampedSignal = std::max(-20.0f, std::min(controlSignal, 20.0f));
            buf = driver_->sendTorqueSetpoint(actuator_id, clampedSignal);
            updateMotorPosition(actuator_id,buf);
        }



}