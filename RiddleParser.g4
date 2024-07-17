parser grammar RiddleParser;

options {
    tokenVocab=RiddleLexer;
}

@Header{
}

@Parser::members {
}

program
    : statement_ed*
    | EOF
    ;

statement_ed
    : statement Semi? Endl?
    ;

statement
    : print
    | packStatement
    | importStatement
    | funcDefine
    | funcExpr
    | varStatement
    | forStatement
    | whileStatement
    | ifStatement
    | returnStatement
    | expression
    | LeftCurly statement_ed* RightCurly
    ;

packStatement
    : Package packName=id
    ;

importStatement
    : Import libName=id
    ;

varStatement
    : Var name=Identifier Colon type=Identifier
    | Var name=Identifier Assign value=expression
    | Var name=Identifier Colon type=Identifier Assign value=expression
    ;

funcExpr
    : funcName=id LeftBracket arge=argsExpr RightBracket
    ;

argsExpr
    : ((expression Comma)* expression)?
    ;

defineArgs
    : ((Identifier Colon id Comma)* (Identifier Colon id))?
    ;

funcDefine
    : Func funcName=Identifier LeftBracket args=defineArgs RightBracket (Colon returnType=id)? LeftCurly body=program RightCurly
    ;

forStatement
    : For LeftBracket (init=varStatement)? Semi (termCond=expression)? Semi (selfVar=statement)? RightBracket body=statement_ed
    ;

whileStatement
    : While LeftBracket runCond=expression RightBracket body=statement_ed
    ;

ifStatement returns [bool hasElse]
    : If LeftBracket cond=expression RightBracket body=statement_ed {$hasElse=false;}
    | If LeftBracket cond=expression RightBracket body=statement_ed Else elseBody=statement_ed {$hasElse=true;}
    ;

returnStatement
    : Return result=statement_ed
    ;

expression
    : LeftBracket expr=expression RightBracket              #bracketExpr    // (x)
    | Not expr=expression                                   #notExpr        // !x
    | Add expr=expression                                   #positiveExpr   // +x
    | Sub expr=expression                                   #negativeExpr   // -x
    | Add Add expr=objectExpr                               #selfAddLeftExpr // ++x
    | expr=objectExpr Add Add                               #selfAddRightExpr // x++
    | Sub Sub expr=objectExpr                               #selfSubLeftExpr // ++x
    | expr=objectExpr Sub Sub                               #selfSubRightExpr // x++
    | left=expression Star right=expression                 #starExpr       // x*y
    | left=expression Div  right=expression                 #divExpr        // x/y
    | left=expression Mod right=expression                  #modExpr        // x%y
    | left=expression Add right=expression                  #addExpr        // x+y
    | left=expression Sub right=expression                  #subExpr        // x-y
    | left=expression LeftLeft right=expression             #leftLeftExpr   // x<<y
    | left=expression RightRight right=expression           #rightRightExpr // x>>y
    | left=expression Greater right=expression              #greaterExpr    // x>y
    | left=expression Less   right=expression               #lessExpr       // x<y
    | left=expression Greater Assign right=expression       #greaterEqualExpr // x>=y
    | left=expression Less Assign right=expression          #lessEqualExpr  // x<=y
    | left=expression Equal  right=expression               #equalExpr      // x==y
    | left=expression Not Equal right=expression            #notEqualExpr   // x!=y
    | left=expression And right=expression                  #bitAndExpr     // x&y
    | left=expression Xor right=expression                  #bitXorExpr     // x^y
    | left=expression Or right=expression                   #bitOrExpr      // x|y
    | left=expression And And right=expression              #andExpr        // x&&y
    | left=expression Or Or right=expression                #orExpr         // x||y
    | left=objectExpr Assign right=expression               #assignExpr     // x=y
    | left=objectExpr Add Assign right=expression           #addAssignExpr     // x+=y
    | left=objectExpr Sub Assign right=expression           #subAssignExpr     // x-=y
    | left=objectExpr Star Assign right=expression          #starAssignExpr    // x*=y
    | left=objectExpr Div Assign right=expression           #divAssignExpr     // x/=y
    | left=objectExpr Mod Assign right=expression           #modAssignExpr     // x%=y
    | left=objectExpr Add Assign right=expression           #addAssignExpr     // x+=y
    | left=objectExpr And Assign right=expression           #andAssignExpr          // x&=y
    | left=objectExpr Or  Assign right=expression           #orAssignExpr           // x|=y
    | left=objectExpr Xor Assign right=expression           #xorAssignExpr          // x^=y
    | left=objectExpr LeftLeft Assign right=expression      #leftLeftAssignExpr     // x<<=y
    | left=objectExpr RightRight Assign right=expression    #rightRightAssignExpr   // x>>=y
    | string                                                #stringExpr
    | number                                                #numberExpr
    | objectExpr                                            #objExpr
    ;

objectExpr
    : id
    ;

id: Identifier (Dot Identifier)*;

//这里是指常量
number
    : integer
    | float
    ;

string
    : STRING
    ;

float returns [double value]
    : Float{
        $value = stod($Float.text);
    }
    ;

integer returns [int value]
    : Decimal{
        $value = stoi($Decimal.text);
    }
    | Hexadecimal{
        $value = stoi($Hexadecimal.text.substr(2),nullptr,16);
    }
    | Binary{
        $value = stoi($Binary.text.substr(2),nullptr,2);
    }
    | Octal{
        $value = stoi($Octal.text.substr(2),nullptr,8);
    }
    ;

// 测试用
print
    : Print '(' value=expression ')'
    ;