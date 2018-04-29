import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.ParseCancellationException;
import org.antlr.v4.runtime.tree.ParseTree;
import grammar.MxLangLexer;
import grammar.MxLangParser;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class MxLangEnvironment {
    private Map<String, Variable> _memory;
    private MxLangVisitor _visitor;

    public Map<String, Variable> getMemory() {
        return _memory;
    }

    public MxLangEnvironment() {
        this._memory = new HashMap<>();
        this._visitor = new MxLangVisitor(_memory);
    }

    private Variable exec(CharStream stream) throws MxLangParsingException {
        try {
            MxLangLexer lexer = new MxLangLexer(stream);
            lexer.removeErrorListeners();
            lexer.removeErrorListener(ConsoleErrorListener.INSTANCE);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            MxLangParser parser = new MxLangParser(tokens);
            ParseTree tree = parser.init();
            return _visitor.visit(tree);
        } catch (ParseCancellationException exc) {
//            System.err.println("1   " + exc);
            throw new MxLangParsingException(exc);
        } catch (RecognitionException exc) {
//            System.err.println("2   " + exc);
            throw new MxLangParsingException(exc);
        }
    }

    public int savedVariablesSize(){
        return _memory.size() - 1;
    }

    public String exec(String command) {
        if (command == null) throw new IllegalArgumentException("Argument 'command' must be not-null value");
        else {
            String output;
            Variable result;
            try {
                result = exec(CharStreams.fromString(command));
                output = result.getValue().toString();
            } catch (MxLangParsingException exc) {
                output = exc.toString();
            }
            return output;
        }
    }

    @Override
    public String toString() {
        return "MxLang ENV: \n" + _memory.entrySet().stream().map((Map.Entry x) -> String.format("%s:%s", x.getKey(), x.getValue())).collect(Collectors.joining("\n"));
    }

}
