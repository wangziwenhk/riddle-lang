#include "RiddleLexer.h"
#include "RiddleParser.h"
#include "Visitors/GenVisitor.h"

using namespace std;
using namespace antlr4;
int main(int argv,char *argc[]){
    if(argv<2)return 0;
    ifstream file(argc[1]);
    ANTLRInputStream stream(file);
    RiddleLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    RiddleParser parser(&tokens);

    tree::ParseTree* p = parser.program();
    //按理来说这里一个有一个优化的，但是还没写

    GenVisitor visitor;
    visitor.visit(p);
    return 0;
}
