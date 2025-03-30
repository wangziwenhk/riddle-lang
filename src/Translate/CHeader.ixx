// ReSharper disable CppLocalVariableMayBeConst
module;
#include <clang-c/Index.h>
#include <filesystem>
#include <ios>
#include <iostream>
#include <string>
export module Translate.CHeader;
import Semantics.SemNode;
namespace Riddle {
    /// 将 clang-c 的 CXString 转换为 std::string
    std::string toString(const CXString cxString) {
        std::string result = clang_getCString(cxString);
        clang_disposeString(cxString);
        return result;
    }

    bool isFunctionDefinition(const CXCursor &cursor) {
        CXCursor definition = clang_getCursorDefinition(cursor);
        return !clang_Cursor_isNull(definition);
    }
} // namespace Riddle
export namespace Riddle::header {
    /// 获取某个 CXCursor 的子节点
    // ReSharper disable once CppParameterMayBeConst
    // ReSharper disable once CppPassValueParameterByConstReference
    CXChildVisitResult collectChildren(CXCursor cursor, CXCursor parent, CXClientData client_data) {
        auto data = static_cast<std::vector<CXCursor, std::allocator<CXCursor>> *>(client_data);
        data->push_back(cursor);
        return CXChildVisit_Continue; // 只收集直接子节点，不递归
    }

    class CHeaderVisitor {
    public:
        ProgramNode *root;
        SemNode *visit(const CXCursor &cursor) {
            switch (clang_getCursorKind(cursor)) {
                case CXCursor_TranslationUnit:
                    return visitProgram(cursor);
                case CXCursor_FunctionDecl:
                    return visitFunctionDecl(cursor);
                default:
                    break;
            }
            return nullptr;
        }

        SemNode *visitProgram(const CXCursor &cursor) {
            root = new ProgramNode(new BlockNode());

            std::vector<CXCursor> children;
            clang_visitChildren(cursor, collectChildren, &children);
            for (const CXCursor &child: children) {
                SemNode *node = visit(child);
                root->body->push_back(node);
                root->addSemNode(node);
            }
            return root;
        }

        SemNode *visitFunctionDecl(const CXCursor &cursor) {
            std::string name = toString(clang_getCursorSpelling(cursor));
            auto* return_type = new TypeNode(toString(clang_getTypeSpelling(clang_getCursorResultType(cursor))));
            root->addSemNode(return_type);
            BlockNode *block = nullptr;
            return nullptr;
        }
    };

    auto parseCHead(const std::string &filePath) {
        namespace fs = std::filesystem;
        CXIndex index = clang_createIndex(0, 0);
        CXTranslationUnit tu =
                clang_parseTranslationUnit(index, filePath.c_str(), nullptr, 0, nullptr, 0, CXTranslationUnit_None);
        if (!tu) {
            clang_disposeIndex(index);
            throw fs::filesystem_error("File not found", filePath,
                                       std::make_error_code(std::errc::no_such_file_or_directory));
        }

        CXCursor root = clang_getTranslationUnitCursor(tu);

        CHeaderVisitor visitor{};
        auto result = dynamic_cast<ProgramNode *>(visitor.visit(root));

        clang_disposeTranslationUnit(tu);
        clang_disposeIndex(index);
        return result;
    }
} // namespace Riddle::header
