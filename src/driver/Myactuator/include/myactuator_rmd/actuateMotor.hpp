#include <stdint.h>



namespace myactuator_rmd{




    void updateMotorPosition(std::uint32_t actuator_id, Feedback feedback);
      
    void calculateCurrentAngle(std::uint32_t actuator_id, int currentShaftAngle);

    void actuateMotor(std::uint32_t actuator_id,float controlSignal);




}