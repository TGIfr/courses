import java.util.LinkedList;
import java.util.Iterator;

public class TransTableFSM extends FSM {
    private LinkedList<Transition> transitions;

    public TransTableFSM() {
        transitions = new LinkedList<Transition>();
        buildTransitionTable();
    }

    public void buildTransitionTable() {
        transitions.add(new Transition(States.q0, States.q1, Events.BRACE_OPEN));
        transitions.add(new Transition(States.q1, States.q2, Events.DIGIT));
        transitions.add(new Transition(States.q1, States.q3, Events.CAP_LETTER));
        transitions.add(new Transition(States.q2, States.q2, Events.DIGIT));
        transitions.add(new Transition(States.q2, States.q4, Events.BRACE_CLOSE));
        transitions.add(new Transition(States.q3, States.q3, Events.CAP_LETTER));
        transitions.add(new Transition(States.q3, States.q4, Events.BRACE_CLOSE));
    }

    protected States nextState(Events curEvent) {
        Iterator<Transition> iter = transitions.iterator();
        while (iter.hasNext()) {
            Transition thyTransition = iter.next();
            if (_currentState == thyTransition._startEvent && curEvent == thyTransition._trigger) {
                return thyTransition._endEvent;
            }
        }
        return States.ERR;
    }
}
