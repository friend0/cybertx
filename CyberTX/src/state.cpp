#include <iostream>
#include "state.h"

class StateMachine {
    public:
        StateMachine(State initial_state) {
            current_state = initial_state;
        }
        void Update(std::string signal) {
            if(signal == "start") {
                current_state = running;
            }
            // check if we havent received an update in some deadline
        };
    private:
        State current_state;
};