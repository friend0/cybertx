#ifndef STATE_H
#define STATE_H
#include <string>

enum State {waiting, running};

class StateMachine {
    public:
        StateMachine(State initial);
        void Update(std::string);
    private:
        State current_state;       
};

#endif