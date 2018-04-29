
public class FSM {

    protected States currentState;

    public FSM() {
        currentState = States.q0;
    }

    private void start() {
        currentState = States.q0;
    }

    public Events recognizeEvent(char curSymbol) {
        if(Character.isUpperCase(curSymbol))
            return Events.CAP_LETTER;
         else if (Character.isDigit(curSymbol))
            return Events.DIGIT;
         else if (curSymbol == '{')
            return Events.BRACE_OPEN;
         else if (curSymbol == '}')
            return Events.BRACE_CLOSE;
         else
            return Events.OTHER;


    }

    // Default implementation.
    public boolean scanString(String toScan) {
        start();
        if(null == toScan) return false;
        for (int i = 0; i < toScan.length(); i++) {
            Events curEvent = recognizeEvent(toScan.charAt(i));
            currentState = nextState(curEvent);
            if (currentState == States.ERR) {
                return false;
            }
        }
        return currentState == States.q4;
    }

    // Default implementation.
    protected States nextState(Events curEvent) {
        return States.ERR;
    }

}
