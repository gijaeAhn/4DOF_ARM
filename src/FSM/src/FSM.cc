#include "FSM.hpp"


namespace fsm{
FSM::FSM() {
    // Initialize the FSM with a starting state
    State state_;

    // Define state transitions
    transitions[TransitionKey{State::INIT_STATE, "EventA"}] = State::MOTION_STATE;
    transitions[TransitionKey{State::INIT_STATE, "EventB"}] = State::IMPEDENCE_STATE;
    // Add more transitions as necessary
}

void FSM::onEvent(const std::string& event) {
    TransitionKey key{currentState, event};
    if (transitions.find(key) != transitions.end()) {
        currentState = transitions[key];
        // Add any additional actions you want to perform on transition
    } else {
        // Handle invalid event for current state
    }
}
}