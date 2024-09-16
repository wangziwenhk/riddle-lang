parser grammar RiddleParser;

options {
    tokenVocab=RiddleLexer;
}

@Header{
}

@parserFile::members {
}

program
    : statement_ed*
    | EOF
    ;

statement_ed
    : statement Semi? Endl?
    | Semi
    | Endl
    ;

statement
    : packStatement
    | importStatement
    | classDefine
    | funcDefine
    | varDefineStatement
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

varDefineStatement
    : Var name=Identifier Colon type=typeName
    | Var name=Identifier Assign value=expression
    | Var name=Identifier Colon type=typeName Assign value=expression
    ;

argsExpr
    : ((expression Comma)* expression)?
    ;

defineArgs
    : ((Identifier Colon typeName Comma)* (Identifier Colon typeName))?
    ;

funcDefine
    : Func funcName=Identifier LeftBracket args=defineArgs RightBracket (Sub Greater returnType=typeName)? LeftCurly body=funcBody RightCurly
    ;

funcBody
    : statement_ed*
    ;

forStatement
    : For LeftBracket (init=varDefineStatement)? Semi (termCond=expression)? Semi (selfVar=statement)? RightBracket body=statement_ed
    ;

whileStatement
    : While LeftBracket runCond=expression RightBracket body=statement_ed
    ;

ifStatement returns [bool hasElse]
    : If LeftBracket cond=expression RightBracket body=statement_ed {$hasElse=false;}
    | If LeftBracket cond=expression RightBracket body=statement_ed Else elseBody=statement_ed {$hasElse=true;}
    ;

returnStatement
    : Return (result=statement_ed)?
    ;

classDefine
    : Class className = id LeftCurly body=classBody RightCurly
    ;

classBody
    : statement_ed*
    ;

// 这一块就是使用
exprPtr
    : funcName=Identifier LeftBracket args=argsExpr RightBracket    #funcExpr
    | Identifier                                                    #objectExpr
    | parent=exprPtr Dot child=exprPtr                              #blendExpr
    ;

exprPtrParser
    : exprPtr
    ;

expression
    : Less type=typeName Greater LeftBracket value=exprPtrParser RightBracket #castExpr
    | LeftBracket expr=expression RightBracket              #bracketExpr    // (x)
    | Not expr=expression                                   #notExpr        // !x
    | Add expr=expression                                   #positiveExpr   // +x
    | Sub expr=expression                                   #negativeExpr   // -x
    | Add Add expr=exprPtrParser                                  #selfAddLeftExpr // ++x
    | expr=exprPtrParser Add Add                                  #selfAddRightExpr // x++
    | Sub Sub expr=exprPtrParser                                  #selfSubLeftExpr // ++x
    | expr=exprPtrParser Sub Sub                               #selfSubRightExpr // x++
    | exprPtr                                               #ptrExpr
    | left=expression Star right=expression                 #mulExpr        // x*y
    | left=expression Div  right=expression                 #divExpr        // x/y
    | left=expression Mod right=expression                  #modExpr        // x%y
    | left=expression Add right=expression                  #addExpr        // x+y
    | left=expression Sub right=expression                  #subExpr        // x-y
    | left=expression LeftLeft right=expression             #shlExpr        // x<<y
    | left=expression RightRight right=expression           #aShrExpr  // x>>y
    | left=expression RightRightRight right=expression      #lShrExpr  // x>>>y
    | left=expression Greater right=expression              #greaterExpr    // x>y
    | left=expression Less   right=expression               #lessExpr       // x<y
    | left=expression Greater Assign right=expression       #greaterEqualExpr // x>=y
    | left=expression Less Assign right=expression          #lessEqualExpr  // x<=y
    | left=expression Equal  right=expression               #equalExpr      // x==y
    | left=expression Not Assign right=expression           #notEqualExpr   // x!=y
    | left=expression And right=expression                  #bitAndExpr     // x&y
    | left=expression Xor right=expression                  #bitXorExpr     // x^y
    | left=expression Or right=expression                   #bitOrExpr      // x|y
    | left=expression And And right=expression              #andExpr        // x&&y
    | left=expression Or Or right=expression                #orExpr         // x||y
    | left=exprPtrParser Assign right=expression               #assignExpr     // x=y
    | left=exprPtrParser Add Assign right=expression           #addAssignExpr     // x+=y
    | left=exprPtrParser Sub Assign right=expression           #subAssignExpr     // x-=y
    | left=exprPtrParser Star Assign right=expression          #mulAssignExpr    // x*=y
    | left=exprPtrParser Div Assign right=expression           #divAssignExpr     // x/=y
    | left=exprPtrParser Mod Assign right=expression           #modAssignExpr     // x%=y
    | left=exprPtrParser Add Assign right=expression           #addAssignExpr     // x+=y
    | left=exprPtrParser And Assign right=expression           #andAssignExpr          // x&=y
    | left=exprPtrParser Or  Assign right=expression           #orAssignExpr           // x|=y
    | left=exprPtrParser Xor Assign right=expression           #xorAssignExpr          // x^=y
    | left=exprPtrParser LeftLeft Assign right=expression      #shlAssignExpr     // x<<=y
    | left=exprPtrParser RightRight Assign right=expression    #aShrAssignExpr   // x>>=y
    | left=exprPtrParser RightRightRight Assign right=expression    #lShrAssignExpr   // x>>>=y
    | string                                                #stringExpr
    | number                                                #numberExpr
    | boolean                                               #booleanExpr
    ;

id: Identifier (Dot Identifier)*;

//这里是指常量
number
    : integer
    | float
    ;

boolean returns [bool value]
    : True {$value=true;}
    | False {$value=false;}
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
        $value = stoi($Octal.text.substr(1),nullptr,8);
    }
    ;

templateArg
    : expression
    | typeName
    ;

templateArgs
    : ((templateArg Comma)* templateArg)?
    ;

typeName
    : name=id
    | name=id Less args=templateArgs Greater
    | baseType=typeName LeftSquare size=expression RightSquare
    ;