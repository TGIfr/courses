grammar MxLang;
@header {
    package grammar;
}

DOUBLE
   :    ('0' .. '9') + ('.' ('0' .. '9') +)?
   ;

WS
    :   [ \t\r]+ -> skip
    ;
VAR
    :   [a-zA-Z_][a-zA-Z_0-9]*
    ;
NEWLINE
    :   '\n'
    ;

POW
    :   '^'
    ;
PLUS
    :   '+'
    ;
EQUAL
    :   '='
    ;
MINUS
    :   '-'
    ;
MULT
    :   '*'
    ;
DIV
    :   '/'
    ;
LPAREN
    :   '('
    ;
RPAREN
    :   ')'
    ;
LBRACKET
    :   '['
    ;
RBRACKET
    :   ']'
    ;
LFIGURE
    :   '{'
    ;
RFIGURE
    :   '}'
    ;
MODULE
    :   '|'
    ;

number
    : DOUBLE
    ;
variable
    :   VAR
    ;
array
    :   LFIGURE expression  (',' expression)* RFIGURE
    ;
matrix
    :   LBRACKET expression (',' expression)* RBRACKET
    ;
atom
    :   variable
    |   number
    |   LPAREN expression RPAREN
    |   matrix
    |   array
    ;

signedAtom
   :   PLUS signedAtom      # PlainAtom
   |   MINUS signedAtom     # InvertSignedAtom
   |   atom                 # PlainAtom
   ;

factor
    :   signedAtom (POW signedAtom)?
    ;
expression
    :   expression DIV expression       # DivExpression
    |   expression MULT expression      # MultExpression
    |   expression PLUS expression      # SumExpression
    |   expression MINUS expression     # SubtractExpression
    |   'det('expression')'             # DeterminantExpression
    |   factor                          # PlainFactor
    ;
assign
    :   VAR EQUAL expression
    ;
print
    :    expression NEWLINE?
    |    assign NEWLINE?
    ;
init
    :   print
    ;





