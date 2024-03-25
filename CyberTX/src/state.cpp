// #include <iostream>
#include "state.h"

StateMachine::StateMachine(State initial_state = waiting) {
            current_state = initial_state;
}

void StateMachine::Update(std::string)
{
}
