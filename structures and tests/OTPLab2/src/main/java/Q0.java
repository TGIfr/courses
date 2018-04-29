public class Q0 implements State {

    public void nextState(StateFSM fsm, Events currentEvent) {
        switch(currentEvent) {
            case BRACE_OPEN:
                fsm.setState(new Q1());
                break;
            default:
                fsm.setState(new ERR());
                break;
        }
    }

    public String toString() {
        return "q0";
    }
}
