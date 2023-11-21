#include "myactuator_rmd/driver.hpp"


#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>


namespace robot{

class robotImpedenceController {
    private :
        
        

        myactuator_rmd::Driver* inner_driver_;

    public:

        robotImpedenceController(float pGain, float iGain,float dGain);
        ~robotImpedenceController();

        void setDriver(myactuator_rmd::Driver &driver);

        void addMotor(std::uint32_t actuator_id);



        void ImpedenceControl(std::vector<double> xyzGain);

    protected:
    
        void updateMotorPosition(std::uint32_t actuator_id, myactuator_rmd::Feedback feedback);
      
        void calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle);

        void actuateMotor(std::uint32_t actuator_id,float controlSignal);
};



}