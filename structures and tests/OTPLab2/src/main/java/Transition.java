public class Transition {
    protected States from;
    protected States to;
    protected Events ev;

    public Transition(States from, States to, Events curEvent) {
        this.from = from;
        this.to = to;
        ev = curEvent;
    }

}
