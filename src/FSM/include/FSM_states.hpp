#ifndef FSM_STATES_H
#define FSM_STATES_H

namespace fsm {
enum class State {
    INIT_STATE,
    MOTION_STATE,
    IMPEDANCE_STATE,
    GRAVITY_COMPENSATION_STATE
    // Add more states as needed
};

}

#endif // FSM_STATES_H