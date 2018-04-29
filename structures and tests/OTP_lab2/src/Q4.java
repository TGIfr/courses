public class Q4 implements State {
    public void doAction(StateFSM fsm, Events curEvent) {

        fsm.setState(new ERR());
    }

    public String toString() {
        return "q4";
    }
}
