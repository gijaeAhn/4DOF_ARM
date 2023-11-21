#include "FSM_body.hpp"


namespace fsm{
FSM::FSM() {
    // Initialize the FSM with a starting state
    currentState = State:

    // Define state transitions
    transitions[TransitionKey{State::State1, "EventA"}] = State::State2;
    transitions[TransitionKey{State::State2, "EventB"}] = State::State3;
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