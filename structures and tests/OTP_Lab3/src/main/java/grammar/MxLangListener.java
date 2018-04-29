// Generated from MxLang.g4 by ANTLR 4.7.1

    package grammar;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MxLangParser}.
 */
public interface MxLangListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MxLangParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(MxLangParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(MxLangParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(MxLangParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(MxLangParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(MxLangParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(MxLangParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#matrix}.
	 * @param ctx the parse tree
	 */
	void enterMatrix(MxLangParser.MatrixContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#matrix}.
	 * @param ctx the parse tree
	 */
	void exitMatrix(MxLangParser.MatrixContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom(MxLangParser.AtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom(MxLangParser.AtomContext ctx);
	/**
	 * Enter a parse tree produced by the {@code PlainAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 */
	void enterPlainAtom(MxLangParser.PlainAtomContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PlainAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 */
	void exitPlainAtom(MxLangParser.PlainAtomContext ctx);
	/**
	 * Enter a parse tree produced by the {@code InvertSignedAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 */
	void enterInvertSignedAtom(MxLangParser.InvertSignedAtomContext ctx);
	/**
	 * Exit a parse tree produced by the {@code InvertSignedAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 */
	void exitInvertSignedAtom(MxLangParser.InvertSignedAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(MxLangParser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(MxLangParser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SubtractExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSubtractExpression(MxLangParser.SubtractExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SubtractExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSubtractExpression(MxLangParser.SubtractExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code PlainFactor}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPlainFactor(MxLangParser.PlainFactorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PlainFactor}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPlainFactor(MxLangParser.PlainFactorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SumExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSumExpression(MxLangParser.SumExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SumExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSumExpression(MxLangParser.SumExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DivExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterDivExpression(MxLangParser.DivExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DivExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitDivExpression(MxLangParser.DivExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DeterminantExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterDeterminantExpression(MxLangParser.DeterminantExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DeterminantExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitDeterminantExpression(MxLangParser.DeterminantExpressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MultExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMultExpression(MxLangParser.MultExpressionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MultExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMultExpression(MxLangParser.MultExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#assign}.
	 * @param ctx the parse tree
	 */
	void enterAssign(MxLangParser.AssignContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#assign}.
	 * @param ctx the parse tree
	 */
	void exitAssign(MxLangParser.AssignContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#print}.
	 * @param ctx the parse tree
	 */
	void enterPrint(MxLangParser.PrintContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#print}.
	 * @param ctx the parse tree
	 */
	void exitPrint(MxLangParser.PrintContext ctx);
	/**
	 * Enter a parse tree produced by {@link MxLangParser#init}.
	 * @param ctx the parse tree
	 */
	void enterInit(MxLangParser.InitContext ctx);
	/**
	 * Exit a parse tree produced by {@link MxLangParser#init}.
	 * @param ctx the parse tree
	 */
	void exitInit(MxLangParser.InitContext ctx);
}