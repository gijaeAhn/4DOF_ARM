#ifndef FSM_UTILITIES_H
#define FSM_UTILITIES_H

#include "FSM_states.hpp"
#include <map>
#include <string>


namespace fsm{
struct Transition {
    fsm::State currentState;
    std::string event;

    Transition(fsm::State current, const std::string& evt)
        : currentState(current), event(evt){}
};


struct TransitionKey {
    fsm::State currentState;
    std::string event;

    bool operator<(const TransitionKey& other) const {
        return currentState < other.currentState || (currentState == other.currentState && event < other.event);
    }
};

}

#endif // FSM_UTILITIES_H