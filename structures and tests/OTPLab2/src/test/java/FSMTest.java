import static org.junit.jupiter.api.Assertions.*;
import org.junit.Test;

import java.util.stream.Stream;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.*;

import org.junit.jupiter.api.extension.ExtensionContext;

public class FSMTest {

    private SwitchFSM fsmSwitch;
    private TransTableFSM fsmTT;
    private StateFSM fsmState;

    @BeforeEach
    public void init() {
        fsmSwitch = new SwitchFSM();
        fsmTT = new TransTableFSM();
        fsmState = new StateFSM();
    }

    @ParameterizedTest
    @ValueSource(strings = {"{4}", "{488484}", "{ADJVYUJGN}","{A}" })
    public void StrTrueValueTest(String str) {

        assertTrue(fsmSwitch.scanString(str));
        assertTrue(fsmTT.scanString(str));
        assertTrue(fsmState.scanString(str));
    }

    @ParameterizedTest
    @ValueSource(strings = {"{", "}", ""," ", "{Adf}", "{n}", "{Ad}" })
    public void StrFalseValueTest(String str) {

        assertFalse(fsmSwitch.scanString(str));
        assertFalse(fsmTT.scanString(str));
        assertFalse(fsmState.scanString(str));
    }

    static Stream<Arguments> trueStr() {
        return Stream.of(Arguments.of("{4}", true),
                Arguments.of("{488484}", true),
                Arguments.of("{ADJVYUJGN}", true),
                Arguments.of("{A}", true));

    }
    static Stream<Arguments> falseStr() {
        return Stream.of(
                Arguments.of("{", false),
                Arguments.of("}", false),
                Arguments.of("", false),
                Arguments.of(" ", false),
                Arguments.of("{Adf}", false),
                Arguments.of("{n}", false));
    }

    @ParameterizedTest
    @MethodSource(value = {"trueStr", "falseStr"})
    public void MethodSourceTest(String str, boolean exp) {

        assertEquals(exp, fsmSwitch.scanString(str));
        assertEquals(exp, fsmTT.scanString(str));
        assertEquals(exp, fsmState.scanString(str));
    }








    @ParameterizedTest
    @CsvFileSource(resources = "/data.csv")
    void CsvTest(String str, boolean exp) {
        assertEquals(exp, fsmSwitch.scanString(str));
        assertEquals(exp, fsmTT.scanString(str));
        assertEquals(exp, fsmState.scanString(str));
    }

    @ParameterizedTest
    @ArgumentsSource(CustomArgumentProvider.class)
    void ParametrizedTest(String str, boolean exp) {
        assertEquals(exp, fsmSwitch.scanString(str));
        assertEquals(exp, fsmTT.scanString(str));
        assertEquals(exp, fsmState.scanString(str));
    }

    static class CustomArgumentProvider implements ArgumentsProvider {

        @Override
        public Stream<? extends Arguments> provideArguments(ExtensionContext context) throws Exception {
            return Stream.of(
                    Arguments.of("{", false),
                    Arguments.of("}", false),
                    Arguments.of("", false),
                    Arguments.of(" ", false),
                    Arguments.of("{Adf}", false),
                    Arguments.of("{n}", false),
                    Arguments.of("{4}", true),
                    Arguments.of("{488484}", true),
                    Arguments.of("{ADJVYUJGN}", true),
                    Arguments.of("{A}", true));
        }
    }

    @Test
    public void NullTest(){
        assertFalse(fsmSwitch.scanString(null));
        assertFalse(fsmTT.scanString(null));
        assertFalse(fsmState.scanString(null));
    }



}