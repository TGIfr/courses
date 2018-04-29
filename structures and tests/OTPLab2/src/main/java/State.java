public interface State {
    void nextState(StateFSM fsm, Events currentEvent);
}
