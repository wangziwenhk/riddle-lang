#include "RiddleLexer.h"
#include "RiddleParser.h"
#include "Visitors/PackageVisitor.h"
using namespace std;
using namespace antlr4;
int main(int argv, char *argc[]) {
    if(argv < 2) return 0;
    ifstream file(argc[1]);
    ANTLRInputStream stream(file);
    RiddleLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    RiddleParser parser(&tokens);

    tree::ParseTree *p = parser.program();
    return 0;
}
