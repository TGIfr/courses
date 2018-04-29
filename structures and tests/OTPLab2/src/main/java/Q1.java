public class Q1 implements State {
    public void nextState(StateFSM fsm, Events currentEvent) {
        switch(currentEvent) {
            case DIGIT:
                fsm.setState(new Q2());
                break;
            case CAP_LETTER:
                fsm.setState(new Q3());
                break;
            default:
                fsm.setState(new ERR());
                break;
        }
    }

    public String toString() {
        return "q1";
    }
}
