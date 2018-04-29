import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.DisplayName;

import java.awt.*;
import java.util.stream.Stream;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import org.junit.jupiter.api.extension.ExtensionContext;
import org.junit.jupiter.params.provider.CsvFileSource;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.ArgumentsSource;
import org.junit.jupiter.params.provider.ArgumentsProvider;

class FSMTest {

    private SwitchFSM fsm1;
    private TransitionTable fsm2;
    private StateFSM fsm3;

    @org.junit.jupiter.api.Test
    static Stream<Arguments> trueChars () {
        return Stream.of(Arguments.of('#', Event.SHARP),
                Arguments.of('0', Event.DIGIT),
                Arguments.of('O', Event.LETTER),
                Arguments.of('_', Event.SPACE),
                Arguments.of('&', Event.AND),
                Arguments.of('*', Event.PERCENT));

    }
    static Stream<Arguments> falseChars () {
        return Stream.of(Arguments.of('o', null),
                Arguments.of(' ', null),
                Arguments.of(';', null));
    }
    @ParameterizedTest
    @MethodSource(value = {"trueChars", "falseChars"})
    void recognizeEvent(char c, Event exp) {
        fsm1 = new SwitchFSM();
        assertEquals(exp,fsm1.recognizeEvent(c));
    }

    @org.junit.jupiter.api.Test
    @ParameterizedTest
    @CsvFileSource(resources = "/test-data.csv")
    void scan(String str, boolean exp) {
        System.out.printf(str + exp + '\n');
        fsm1 = new SwitchFSM();
        fsm2 = new TransitionTable();
        fsm3 = new StateFSM();

        assertEquals(exp,fsm1.scan(str));
        assertEquals(exp,fsm2.scan(str));
        assertEquals(exp,fsm3.scan(str));
    }

    @org.junit.jupiter.api.Test
    @ParameterizedTest(name = "{index} => start={0}, e={1}, end={2}")
    @ArgumentsSource(CustomArgumentProvider.class)
    void nextState(State start, Event e, State end) {
        fsm1 = new SwitchFSM();
        fsm2 = new TransitionTable();

        fsm1.currentState = start;
        fsm2.currentState = start;
        assertEquals(end, fsm1.nextState(e));
        assertEquals(end, fsm2.nextState(e));

    }

    static class CustomArgumentProvider implements ArgumentsProvider {

        @Override
        public Stream<? extends Arguments> provideArguments(ExtensionContext context) throws Exception {
            return Stream.of(
                    Arguments.of(State.q0, Event.SPACE, State.q1),
                    Arguments.of(State.q2, Event.DIGIT, State.q2),
                    Arguments.of(State.q3, Event.AND, State.q4)
            );
        }
    }

    @org.junit.jupiter.api.Test
    @ParameterizedTest(name = "{index} => start={0}, e={1}, end={2}")
    @ArgumentsSource(StateArgumentProvider.class)
    void nextState_StateFsm(AbstState start, Event e, AbstState end) {
        fsm3 = new StateFSM();

        fsm3.currentState = start;
        assertTrue(end.getClass() == fsm3.nextState(e).getClass());

    }

    static class StateArgumentProvider implements ArgumentsProvider {

        @Override
        public Stream<? extends Arguments> provideArguments(ExtensionContext context) throws Exception {
            AbstState q0 = new Q0();
            AbstState q1 = new Q1();
            AbstState q2 = new Q2();
            return Stream.of(
                    Arguments.of(q0, Event.SPACE, q1),
                    Arguments.of(q2, Event.DIGIT, q2)

            );
        }
    }

}