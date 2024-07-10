lexer grammar RiddleLexer;
//关键字
Var:'var';
For:'for';
While:'while';
If:'if';
Else:'else';
Func:'func';
Return: 'return' ;
Import: 'import' ;
Package: 'package';
Class:  'class';
Public: 'public';
Protected: 'protected';
Private: 'Private' ;
Override: 'override';
//可见字符
//基本运算符
LeftBracket:    '(';
RightBracket:   ')';
LeftCurly:      '{';
RightCurly:     '}';
Colon:          ':';
Semi:           ';';
Comma:          ',';
Equal:          '==';
Assign:         '=';
Greater:        '>';
Less:           '<';
LeftLeft:       '<<';
RightRight:     '>>';
Add:            '+';
Sub:            '-';
Star:           '*';
Div:            '/';
Mod:            '%';
Not:            '!';
And:            '&';
Or:             '|';
Xor:            '^';
Dot:            '.';
DoubleQuotes:   '"';
Quotes:         '\'';

Endl:'\n';
//标识符
Identifier: [A-Za-z_] [A-Za-z_0-9]*;
//十六进制
Hexadecimal: '0x' [1-9A-F] HEX_DIGIT*;
//十进制
Decimal: '0' | [1-9] DIGIT*;
//八进制
Octal: '0' [1-7] OCTAL_DIGIT*;
//二进制
Binary: '0b' '1' BINARY_DIGIT*;
Float: Decimal Dot IntegerSequence;

IntegerSequence: DIGIT+;
HEX_DIGIT: [0-9A-F];
OCTAL_DIGIT: [0-7];
BINARY_DIGIT: [0-1];
DIGIT: [0-9];
STRING
    : '"' (ESC | ~["\\\r\n])* '"'
    ;

fragment ESC
    : '\\' (["\\/bfnrt] | [A-Za-z])
    ;

LINE_COMMENT : '//' ~[\r\n]* -> skip ;
BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
WHITESPACE : [ \t\r\n]+ -> skip ;