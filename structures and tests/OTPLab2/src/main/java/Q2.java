public class Q2 implements State {

    public void nextState(StateFSM fsm, Events currentEvent) {

        switch(currentEvent) {
            case DIGIT:
                fsm.setState(new Q2());
                break;
            case BRACE_CLOSE:
                fsm.setState(new Q4());
                break;
            default:
                fsm.setState(new ERR());
                break;
        }
    }

    public String toString() {
        return "q2";
    }
}
