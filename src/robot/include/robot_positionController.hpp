#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "robot_body.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <thread>


namespace robot{

class robotPositionController {
    private :

        Robot* robot_;

   
        
        const float errorThreshold = 0.01;
                
        float proportionalGain;
        float integralGain;
        float derivativeGain;


        

        

    public:

        robotPositionController(float pGain, float iGain,float dGain,Robot* robot);

        ~robotPositionController();


        void PIDcontrol(std::vector<std::uint32_t> actuator_id, std::vector<double> setpoint, int maxIterations);


    
        
};



}