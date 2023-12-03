#include "FSM.hpp"


namespace fsm{
FSM::FSM() {
    // Initialize the FSM with a starting state
    currentState = State::INIT_STATE;

    // Define state transitions
    transitions[TransitionKey{State::INIT_STATE, "Move"}] = State::MOTION_STATE;
    transitions[TransitionKey{State::INIT_STATE, "Impedance"}] = State::IMPEDANCE_STATE;
    transitions[TransitionKey{State::MOTION_STATE, "Stop"}] = State::INIT_STATE;
    transitions[TransitionKey{State::MOTION_STATE, "Imepdance"}] = State::IMPEDANCE_STATE;
    transitions[TransitionKey{State::IMPEDANCE_STATE, "Stop"}] = State::INIT_STATE;
    transitions[TransitionKey{State::IMPEDANCE_STATE, "Move"}] = State::MOTION_STATE;

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