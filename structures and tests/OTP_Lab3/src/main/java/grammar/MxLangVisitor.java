// Generated from MxLang.g4 by ANTLR 4.7.1

    package grammar;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MxLangParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MxLangVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MxLangParser#number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumber(MxLangParser.NumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(MxLangParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#array}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray(MxLangParser.ArrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#matrix}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMatrix(MxLangParser.MatrixContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#atom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom(MxLangParser.AtomContext ctx);
	/**
	 * Visit a parse tree produced by the {@code PlainAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlainAtom(MxLangParser.PlainAtomContext ctx);
	/**
	 * Visit a parse tree produced by the {@code InvertSignedAtom}
	 * labeled alternative in {@link MxLangParser#signedAtom}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInvertSignedAtom(MxLangParser.InvertSignedAtomContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFactor(MxLangParser.FactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SubtractExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubtractExpression(MxLangParser.SubtractExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code PlainFactor}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlainFactor(MxLangParser.PlainFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SumExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSumExpression(MxLangParser.SumExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DivExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivExpression(MxLangParser.DivExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DeterminantExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeterminantExpression(MxLangParser.DeterminantExpressionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MultExpression}
	 * labeled alternative in {@link MxLangParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultExpression(MxLangParser.MultExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#assign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign(MxLangParser.AssignContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#print}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrint(MxLangParser.PrintContext ctx);
	/**
	 * Visit a parse tree produced by {@link MxLangParser#init}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInit(MxLangParser.InitContext ctx);
}