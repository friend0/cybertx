#include <string>

enum State {waiting, running};

class StateMachine {
    public:
        StateMachine(State initial=waiting);
        void Update(std::string);
    private:
        State current_state;       
};