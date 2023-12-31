// FSM_body.h
#ifndef FSM_BODY_H
#define FSM_BODY_H

#include "FSM_utilities.hpp"
#include "FSM_states.hpp"
#include <map>

namespace fsm {
class FSM {
private:
    State currentState;
    std::map<TransitionKey, State> transitions;

public:
    FSM();
    void onEvent(const std::string& event);
    
};

}

#endif // FSM_BODY_H