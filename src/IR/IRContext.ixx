module;
#include <iomanip>
#include <iostream>
#include <vector>
export module IR.IRContext;
export import IR.Instruct;
export namespace Riddle {
    class IRContext {
    public:
        std::vector<Instruct *> body;

        void print(std::ostream &os) const {
            for(const auto &i: body) {
                using namespace std;
                os << left;
                switch(i->getInstType()) {
                    case Instruct::Alloca: {
                        const auto alloca = dynamic_cast<AllocaInst *>(i);
                        os << setw(10) << "alloca" << setw(10) << alloca->type->name << endl;
                        break;
                    }
                    case Instruct::FuncCall: {
                        const auto funcCall = dynamic_cast<FuncCallInst *>(i);
                        os << setw(10) << "funcCall" << setw(10) << funcCall->getFuncName();
                        os << setw(10) << "{";
                        for(auto it = funcCall->getArgBegin(); it != funcCall->getArgEnd(); ++it) {
                            os << (*it)->getName() << " ";
                        }
                        os << "}" << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
    };
}// namespace Riddle