module;
#include <string>
#include <utility>
#include <vector>
export module Type.Template;
import IR.Statements;
export namespace Riddle {
    class Template {
    public:
        class TemplateArg {
        public:
            std::string name;
            TmplDefineArgStmt::TmplTypeID type;
            explicit TemplateArg(const TmplDefineArgStmt &stmt): name(stmt.name), type(stmt.tmplTypeID) {}
            TemplateArg(std::string name, const TmplDefineArgStmt::TmplTypeID type): name(std::move(name)), type(type) {}
        };
        std::vector<TemplateArg> args;
        Template() = default;
        explicit Template(const std::vector<TemplateArg> &args): args(args) {}
        explicit Template(const TmplDefineStmt *tmplStmt) {
            for(const auto i: tmplStmt->args) {
                args.emplace_back(*i);
            }
        }
    };
}// namespace Riddle