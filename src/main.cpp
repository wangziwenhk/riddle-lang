#include "RiddleParser.h"
#include "RiddleLexer.h"
#include <iostream>
using namespace std;
using namespace antlr4;
int main(){
    ANTLRInputStream input("");
    RiddleLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    RiddleParser parser(&tokens);

    tree::ParseTree* p = parser.program();

    return 0;
}
