#ifndef ROBOT_PID_ERROR
#define ROBOT_PID_ERROR

namespace robot{
struct PID_ERROR{
    
    double previousError_;

    double error_;
    double integralError_;
    double derivativeError_;

    PID_ERROR(double previousError, double error, double integralError, double derivativeError) 
    :previousError_(previousError),  error_(error),  integralError_(integralError), derivativeError_(derivativeError)
    {}

    void setError(double error ,double ivalue, double deriva){
        error_ = error;

        integralError_ += ivalue;
        derivativeError_ = deriva;  
    }
};

}
#endif