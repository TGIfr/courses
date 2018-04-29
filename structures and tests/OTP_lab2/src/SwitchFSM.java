public class SwitchFSM extends FSM {

    protected States nextState(Events curEvent) {
        switch (_currentState) {
            case q0:
                switch(curEvent) {
                    case BRACE_OPEN:
                        return States.q1;
                    default:
                        return States.ERR;
                }

            case q1:
                switch(curEvent) {
                    case DIGIT:
                        return States.q2;
                    case CAP_LETTER:
                        return States.q3;
                    default:
                        return States.ERR;
                }

            case q2:
                switch(curEvent) {
                    case DIGIT:
                        return States.q2;
                    case BRACE_CLOSE:
                        return States.q4;
                    default:
                        return States.ERR;
                }

            case q3:
                switch(curEvent) {
                    case CAP_LETTER:
                        return States.q3;
                    case BRACE_CLOSE:
                        return States.q4;
                    default:
                        return States.ERR;
                }

            case q4:
                return States.ERR;


            case ERR:
            default:
                return States.ERR;
        }
    }

}
