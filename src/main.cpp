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

    Riddle::PackageVisitor visitor(argc[1]);
    visitor.visit(p);
    std::cout<<visitor.unit.getImportSize();
    return 0;
}
