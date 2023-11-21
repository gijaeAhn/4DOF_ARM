#ifndef FSM_UTILITIES_H
#define FSM_UTILITIES_H

#include "FSM_states.hpp"
#include <map>
#include <string>


namespace {
struct Transition {
    fsm::State currentState;
    std::string event;
    fsm::State nextState;

    Transition(fsm::State current, const std::string& evt, fsm::State next)
        : currentState(current), event(evt), nextState(next) {}
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