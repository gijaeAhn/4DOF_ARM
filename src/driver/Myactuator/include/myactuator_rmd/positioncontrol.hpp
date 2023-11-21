#include "myactuator_rmd/driver.hpp"
#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>
namespace myactuator_rmd{

class MotorPositionController {
    private :
        const int oneShaftCycle = 40;
        const int maxShaftAngle = 65535;
        const int gearRatio = 9;
        const float errorThreshold = 0.5;
        
        std::vector<int> previousShaftAngle;
        std::vector<double> currentAngle;
        
        float proportionalGain;
        float integralGain;
        float derivativeGain;

        Driver* inner_driver_;
        std::mutex mtx_;


    public:

        MotorPositionController(float pGain, float iGain,float dGain, const std::string& ifname) ;

        ~MotorPositionController();

        void addMotor(std::uint32_t actuator_id);

        void showCurrentAngle(std::uint32_t actuator_id);

        void PIDcontrol(std::vector<std::uint32_t> actuator_id, std::vector<double> setpoint, int maxIterations);

    protected:
    
        void updateMotorPosition(std::uint32_t actuator_id, Feedback feedback);
      
        void calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle);

        void actuateMotor(std::uint32_t actuator_id,float controlSignal);
};



}