public class Q3 implements State {
    public void doAction(StateFSM fsm, Events curEvent) {

        switch(curEvent) {
            case CAP_LETTER:
                fsm.setState(new Q3());
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
        return "q3";
    }
}
