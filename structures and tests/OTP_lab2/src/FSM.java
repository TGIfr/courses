
public class FSM {

    protected States _currentState;

    public FSM() {
        _currentState = States.q0;
    }

    private void start() {
        _currentState = States.q0;
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
        for (int i = 0; i < toScan.length(); i++) {
            Events curEvent = recognizeEvent(toScan.charAt(i));
            _currentState = nextState(curEvent);
            if (_currentState == States.ERR) {
                return false;
            }
        }
        return _currentState == States.q4;
    }

    // Default implementation.
    protected States nextState(Events curEvent) {
        return States.ERR;
    }

}
