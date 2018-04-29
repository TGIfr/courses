// Generated from MxLang.g4 by ANTLR 4.7.1

    package grammar;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MxLangLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, DOUBLE=3, WS=4, VAR=5, NEWLINE=6, POW=7, PLUS=8, EQUAL=9, 
		MINUS=10, MULT=11, DIV=12, LPAREN=13, RPAREN=14, LBRACKET=15, RBRACKET=16, 
		LFIGURE=17, RFIGURE=18, MODULE=19;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "DOUBLE", "WS", "VAR", "NEWLINE", "POW", "PLUS", "EQUAL", 
		"MINUS", "MULT", "DIV", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LFIGURE", 
		"RFIGURE", "MODULE"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "','", "'det('", null, null, null, "'\n'", "'^'", "'+'", "'='", 
		"'-'", "'*'", "'/'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'|'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, "DOUBLE", "WS", "VAR", "NEWLINE", "POW", "PLUS", "EQUAL", 
		"MINUS", "MULT", "DIV", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LFIGURE", 
		"RFIGURE", "MODULE"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public MxLangLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MxLang.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\25g\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\6\4\62\n\4\r\4\16"+
		"\4\63\3\4\3\4\6\48\n\4\r\4\16\49\5\4<\n\4\3\5\6\5?\n\5\r\5\16\5@\3\5\3"+
		"\5\3\6\3\6\7\6G\n\6\f\6\16\6J\13\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13"+
		"\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22"+
		"\3\23\3\23\3\24\3\24\2\2\25\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25"+
		"\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25\3\2\5\5\2\13\13\17\17"+
		"\"\"\5\2C\\aac|\6\2\62;C\\aac|\2k\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2"+
		"\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3"+
		"\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2"+
		"\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\3)\3\2\2"+
		"\2\5+\3\2\2\2\7\61\3\2\2\2\t>\3\2\2\2\13D\3\2\2\2\rK\3\2\2\2\17M\3\2\2"+
		"\2\21O\3\2\2\2\23Q\3\2\2\2\25S\3\2\2\2\27U\3\2\2\2\31W\3\2\2\2\33Y\3\2"+
		"\2\2\35[\3\2\2\2\37]\3\2\2\2!_\3\2\2\2#a\3\2\2\2%c\3\2\2\2\'e\3\2\2\2"+
		")*\7.\2\2*\4\3\2\2\2+,\7f\2\2,-\7g\2\2-.\7v\2\2./\7*\2\2/\6\3\2\2\2\60"+
		"\62\4\62;\2\61\60\3\2\2\2\62\63\3\2\2\2\63\61\3\2\2\2\63\64\3\2\2\2\64"+
		";\3\2\2\2\65\67\7\60\2\2\668\4\62;\2\67\66\3\2\2\289\3\2\2\29\67\3\2\2"+
		"\29:\3\2\2\2:<\3\2\2\2;\65\3\2\2\2;<\3\2\2\2<\b\3\2\2\2=?\t\2\2\2>=\3"+
		"\2\2\2?@\3\2\2\2@>\3\2\2\2@A\3\2\2\2AB\3\2\2\2BC\b\5\2\2C\n\3\2\2\2DH"+
		"\t\3\2\2EG\t\4\2\2FE\3\2\2\2GJ\3\2\2\2HF\3\2\2\2HI\3\2\2\2I\f\3\2\2\2"+
		"JH\3\2\2\2KL\7\f\2\2L\16\3\2\2\2MN\7`\2\2N\20\3\2\2\2OP\7-\2\2P\22\3\2"+
		"\2\2QR\7?\2\2R\24\3\2\2\2ST\7/\2\2T\26\3\2\2\2UV\7,\2\2V\30\3\2\2\2WX"+
		"\7\61\2\2X\32\3\2\2\2YZ\7*\2\2Z\34\3\2\2\2[\\\7+\2\2\\\36\3\2\2\2]^\7"+
		"]\2\2^ \3\2\2\2_`\7_\2\2`\"\3\2\2\2ab\7}\2\2b$\3\2\2\2cd\7\177\2\2d&\3"+
		"\2\2\2ef\7~\2\2f(\3\2\2\2\b\2\639;@H\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}