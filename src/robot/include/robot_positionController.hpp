#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>


namespace robot{

class robotPositionController {
    private :
        
        const float errorThreshold = 0.5;
                
        float proportionalGain;
        float integralGain;
        float derivativeGain;

        myactuator_rmd::Driver* inner_driver_;

    public:

        robotPositionController(float pGain, float iGain,float dGain, const std::string& ifname) ;

        ~robotPositionController();

        void addMotor(std::uint32_t actuator_id);

        void showCurrentAngle(std::uint32_t actuator_id);

        void PIDcontrol(std::vector<std::uint32_t> actuator_id, std::vector<double> setpoint, int maxIterations);

    protected:
    
        void updateMotorPosition(std::uint32_t actuator_id, Feedback feedback);
      
        void calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle);

        void actuateMotor(std::uint32_t actuator_id,float controlSignal);
};



}