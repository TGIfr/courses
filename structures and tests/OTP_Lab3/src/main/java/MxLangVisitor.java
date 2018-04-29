
import org.antlr.v4.runtime.misc.ParseCancellationException;
import grammar.MxLangBaseVisitor;
import grammar.MxLangParser;

import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;


public class MxLangVisitor extends MxLangBaseVisitor<Variable> {
    private Map<String, Variable> memory;

    public MxLangVisitor(Map<String, Variable> storage) {
        if (storage == null) {
            throw new IllegalArgumentException("Argument 'storage' is null");
        }
        this.memory = storage;
    }


    // VARIABLE=expression
    @Override
    public Variable visitAssign(MxLangParser.AssignContext ctx) {
        String variableName = ctx.VAR().getText();
        Variable value = visit(ctx.expression());
        memory.put(variableName, value);
        return value;
    }

    // expression | assign
    @Override
    public Variable visitPrint(MxLangParser.PrintContext ctx) {
        Variable result = visit(ctx.expression() != null ? ctx.expression() : ctx.assign());
        memory.put("_", result);
        return new Variable<>(String.valueOf(result.getValue()), String.class);
    }

    @Override
    public Variable visitNumber(MxLangParser.NumberContext ctx) {
        try {
            return new Variable<>(Double.parseDouble(ctx.DOUBLE().getText()), Double.class);
        } catch (NumberFormatException exc) {
            throw new ParseCancellationException(String.format("Invalid number format '%s'", ctx.DOUBLE().getText()));
        }
    }

    // VARIABLE | NUMBER | matrix
    @Override
    public Variable visitAtom(MxLangParser.AtomContext ctx) {
        if (ctx.variable() != null) {
            String varID = ctx.variable().getText();
            try {
                Variable v = memory.get(varID);
                if (v == null) {
                    throw new NoSuchElementException();
                } else {
                    return v;
                }
            } catch (NoSuchElementException exception) {
                throw new ParseCancellationException(String.format("Variable '%s' is undefined", varID));
            }
        } else if (ctx.expression() != null) {
            return visit(ctx.expression());
        } else if (ctx.matrix() != null) {
            return visit(ctx.matrix());
        }  else if (ctx.number() != null) {
            return visit(ctx.number());
        } else if (ctx.array() != null) {
            return visit(ctx.array());
        } else {
            throw new ParseCancellationException(String.format("Cannot recognize type of atom"));
        }
    }

    // +atom |- atom | atom
    @Override
    public Variable visitInvertSignedAtom(MxLangParser.InvertSignedAtomContext ctx) {
        return visit(ctx.signedAtom()).setSign();
    }

    @Override
    public Variable visitPlainFactor(MxLangParser.PlainFactorContext ctx) {
        return visit(ctx.factor());
    }

    @Override
    public Variable visitPlainAtom(MxLangParser.PlainAtomContext ctx) {
        if (ctx.atom() != null) {
            return visit(ctx.atom());
        } else {
            return visit(ctx.signedAtom());
        }
    }


    // expression + expression
    @Override
    public Variable visitSumExpression(MxLangParser.SumExpressionContext ctx) {
        Variable left = visit(ctx.expression(0));
        Variable right = visit(ctx.expression(1));
        if (left == null || right == null) {
            throw new ParseCancellationException("Invalid operation form. It's a binary operation");
        }
        if (!left.getValueType().equals(right.getValueType())) {
            throw new ParseCancellationException(String.format("SUM cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
        }
        try {
            if (left.getValueType().equals(Double.class)) {
                Double leftD = Converter.convertToDouble(left);
                Double rightD = Converter.convertToDouble(right);
                return new Variable<>(leftD + rightD, Double.class);
            } else if (left.getValueType().equals(Matrix.class)) {
                Matrix leftM = Converter.convertToMatrix(left);
                Matrix rightM = Converter.convertToMatrix(right);
                return new Variable<>(leftM.plus(rightM), Matrix.class);
            }
        } catch (IllegalArgumentException | ConvertationException exc) {
            throw new ParseCancellationException("SUM cannot be applied:" + exc.getMessage());
        }
        throw new ParseCancellationException(String.format("SUM cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
    }

    // expression - expression
    @Override
    public Variable visitSubtractExpression(MxLangParser.SubtractExpressionContext ctx) {
        Variable left = visit(ctx.expression(0));
        Variable right = visit(ctx.expression(1));
        if (left == null || right == null) {
            throw new ParseCancellationException("Invalid operation form. It's a binary operation");
        }
        if (!left.getValueType().equals(right.getValueType())) {
            throw new ParseCancellationException(String.format("SUBTRACT cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
        }
        try {
            if (left.getValueType().equals(Double.class)) {
                Double leftD = Converter.convertToDouble(left);
                Double rightD = Converter.convertToDouble(right);
                return new Variable<>(leftD - rightD, Double.class);
            } else if (left.getValueType().equals(Matrix.class)) {
                Matrix leftM = Converter.convertToMatrix(left);
                Matrix rightM = Converter.convertToMatrix(right);
                return new Variable<>(leftM.plus(rightM.multiply(-1)), Matrix.class);
            }
        } catch (ConvertationException | IllegalArgumentException exc) {
            throw new ParseCancellationException("SUBTRACT cannot be applied:" + exc.getMessage());
        }
        throw new ParseCancellationException(String.format("SUBTRACT cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
    }

    private Matrix getMatrixFromLists(List<Variable> members) {
        List first = (List) members.get(0).getValue();
        List<List> arrays = members.stream().map(x -> (List) x.getValue()).collect(Collectors.toList());
        if (arrays.stream().anyMatch(x -> x.size() != first.size())) {
            throw new ParseCancellationException("Matrix definition includes lists with different length");
        }
        double [][] res = new double[arrays.size()][first.size()];
        for(int i = 0; i < arrays.size(); i++){
            for(int j = 0; j < arrays.get(i).size(); j++){
                res[i][j] = (Double) arrays.get(i).get(j);
            }
        }
        return new Matrix(res);
    }

    @Override
    public Variable visitArray(MxLangParser.ArrayContext ctx) {
        // collect all members
        List<Variable> members = ctx.expression().stream().map(this::visit).collect(Collectors.toList());
        if (members.size() == 0 || members.get(0) == null)
            throw new ParseCancellationException("Array definition is empty");
        if (members.stream().anyMatch(x -> !x.getValueType().equals(Double.class))) {
            throw new ParseCancellationException("Array can only contain doubles");
        } else {
            return new Variable<>(
                    members.stream().mapToDouble(x -> (Double) x.getValue()).boxed().collect(Collectors.toList()),
                    List.class);
        }
    }

    // [...]
    @Override
    public Variable visitMatrix(MxLangParser.MatrixContext ctx) {
        // collect all members
        List<Variable> members = ctx.expression().stream().map(this::visit).collect(Collectors.toList());
        Variable first = members.get(0);
        if (first == null) throw new ParseCancellationException("Matrix definition is empty");
        // check, all members has the same type
        if (members.stream().anyMatch(x -> !x.getValueType().equals(first.getValueType()))) {
            throw new ParseCancellationException("Matrix definition includes non-identical members");
        } else if (first.getValueType().equals(Double.class)) {
            // check all members are Double
            double[] source = members.stream().mapToDouble(x -> (Double) x.getValue()).toArray();
            return new Variable<>(new Matrix(new double[][]{source}), Matrix.class);
        } else if (first.getValueType().isAssignableFrom(List.class)) {
            // check all members are Lists
            return new Variable<>(getMatrixFromLists(members), Matrix.class);
        } else {
            throw new ParseCancellationException(String.format("Matrix definition includes unauthorized types: %s", first.getValueType().getName()));
        }
    }

    @Override
    public Variable visitDeterminantExpression(MxLangParser.DeterminantExpressionContext ctx) {
        Variable arg = visit(ctx.expression());
        try {
            return new Variable<>(Converter.convertToMatrix(arg).det(), Double.class);
        } catch (ConvertationException exc) {
            throw new ParseCancellationException("Cannot calculate determinant of not a matrix variable");
        } catch (IllegalArgumentException exc) {
            throw new ParseCancellationException(exc.getMessage());
        }
    }

    private Variable multiplyMatrixByVariable(Matrix matrix, Variable var) {
        if (var.getValueType().equals(Matrix.class)) {
            throw new ParseCancellationException("Multiplication of matrix is not available");
        } else if (var.getValueType().equals(Double.class) || var.getValueType().equals(String.class)) {
            try {
                Double val = Converter.convertToDouble(var);
                return new Variable<>(matrix.multiply((Double) var.getValue()), Matrix.class);
            } catch (ConvertationException exc) {
                throw new ParseCancellationException(String.format("MULT cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
            }
        } else {
            throw new ParseCancellationException(String.format("MULT cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
        }
    }

    private Variable multiplyArrayByDouble(List<Variable> list, Double val) {
        return new Variable<>(list.stream().mapToDouble((Variable x) -> (Double) x.getValue()).map(x -> ((Double) x) * val).boxed().collect(Collectors.toList()), List.class);
    }

    private Variable multiplyArrayByVariable(List<Variable> list, Variable var) {
        if (var.getValueType().equals(List.class)) {
            throw new ParseCancellationException("Multiplication of arrays is not supported yet");
        } else if (var.getValueType().equals(Double.class) || var.getValueType().equals(String.class)) {
            try {
                Double val = Converter.convertToDouble(var);
                return multiplyArrayByDouble(list, val);
            } catch (ConvertationException exc) {
                throw new ParseCancellationException(String.format("MULT cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
            }
        } else {
            throw new ParseCancellationException(String.format("MULT cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
        }
    }

    @Override
    public Variable visitMultExpression(MxLangParser.MultExpressionContext ctx) {
        Variable left = visit(ctx.expression(0));
        Variable right = visit(ctx.expression(1));
        if (left == null || right == null) {
            throw new ParseCancellationException("Invalid operation form. It's a binary operation");
        }
        if (left.getValueType().equals(Matrix.class)) {
            return multiplyMatrixByVariable((Matrix) left.getValue(), right);
        } else if (right.getValueType().equals(Matrix.class)) {
            return multiplyMatrixByVariable((Matrix) right.getValue(), left);
        } else if (left.getValueType().equals(Double.class) && right.getValueType().equals(Double.class)) {
            return new Variable<>(((Double) left.getValue()) * ((Double) right.getValue()), Double.class);
        } else if (left.getValueType().isAssignableFrom(List.class)) {
            return multiplyArrayByVariable((List) left.getValue(), right);
        } else if (right.getValueType().isAssignableFrom(List.class)) {
            return multiplyArrayByVariable((List) right.getValue(), left);
        } else {
            throw new ParseCancellationException(String.format("MULT cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
        }
    }


    private Variable divMatrixByVariable(Matrix matrix, Variable var) {
        if (var.getValueType().equals(Matrix.class)) {
            throw new ParseCancellationException("Division of matrix is not supported");
        } else if (var.getValueType().equals(Double.class) || var.getValueType().equals(String.class)) {
            try {
                Double val = Converter.convertToDouble(var);
                return new Variable<>(matrix.multiply(1 / (Double) var.getValue()), Matrix.class);
            } catch (ConvertationException exc) {
                throw new ParseCancellationException(String.format("DIV cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
            }
        } else {
            throw new ParseCancellationException(String.format("DIV cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
        }
    }

    private Variable divArrayByVariable(List<Variable> list, Variable var) {
        if (var.getValueType().equals(List.class)) {
            throw new ParseCancellationException("Division of arrays is not allowed");
        } else if (var.getValueType().equals(Double.class) || var.getValueType().equals(String.class)) {
            try {
                Double val = Converter.convertToDouble(var);
                return multiplyArrayByDouble(list, 1 / val);
            } catch (ConvertationException exc) {
                throw new ParseCancellationException(String.format("DIV cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
            }
        } else {
            throw new ParseCancellationException(String.format("DIV cannot be applied to operands of type %s and %s", Matrix.class.getName(), var.getValueType().getName()));
        }
    }

    @Override
    public Variable visitDivExpression(MxLangParser.DivExpressionContext ctx) {
        Variable left = visit(ctx.expression(0));
        Variable right = visit(ctx.expression(1));
        if (left == null || right == null) {
            throw new ParseCancellationException("Invalid operation form. It's a binary operation");
        }
        if (left.getValueType().equals(Matrix.class)) {
            return divMatrixByVariable((Matrix) left.getValue(), right);
        } else if (right.getValueType().equals(Matrix.class)) {
            return divMatrixByVariable((Matrix) right.getValue(), left);
        } else if (left.getValueType().equals(Double.class) && right.getValueType().equals(Double.class)) {
            return new Variable<>(((Double) left.getValue()) / ((Double) right.getValue()), Double.class);
        } else if (left.getValueType().isAssignableFrom(List.class)) {
            return divArrayByVariable((List) left.getValue(), right);
        } else if (right.getValueType().isAssignableFrom(List.class)) {
            return divArrayByVariable((List) right.getValue(), left);
        } else {
            throw new ParseCancellationException(String.format("DIV cannot be applied to operands of type %s and %s", left.getValueType().getName(), right.getValueType().getName()));
        }
    }

    @Override
    public Variable visitFactor(MxLangParser.FactorContext ctx) {
        Variable base = visit(ctx.signedAtom(0));
        if (ctx.signedAtom(1) != null) {
            Variable power = visit(ctx.signedAtom(1));
            if (power.getValueType().equals(Double.class) && base.getValueType().equals(Double.class)) {
                return new Variable<>(Math.pow((Double) base.getValue(), (Double) power.getValue()), Double.class);
            } else {
                throw new ParseCancellationException(String.format("POW cannot be applied to object of types %s and %s ", base.getValueType().getName(), power.getValueType().getCanonicalName()));
            }
        } else {
            return base;
        }
    }
}
