public class ERR implements State {
    public void nextState(StateFSM fsm, Events currentEvent) {
        fsm.setState(new ERR());
    }

    public String toString() {
        return "ERR";
    }
}
