#include "RiddleLexer.h"
#include "RiddleParser.h"
using namespace antlr4;
int main(int argv,char *argc[]){
    if(argv<2)return 0;
    ANTLRInputStream stream(argc[1]);
    RiddleLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    RiddleParser parser(&tokens);

    tree::ParseTree* p = parser.program();

    return 0;
}
