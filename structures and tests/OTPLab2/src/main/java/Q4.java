public class Q4 implements State {
    public void nextState(StateFSM fsm, Events currentEvent) {

        fsm.setState(new ERR());
    }

    public String toString() {
        return "q4";
    }
}
