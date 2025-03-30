module;
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <tree_sitter/api.h>
#include <unordered_map>
export module Translate.CHeader;
import Semantics.SemNode;
import Support.FileTools;
extern "C" TSLanguage *tree_sitter_c();
namespace Riddle {
    void traverse_node(const TSNode &node, const char *source, const int depth = 0) {
        // 获取节点类型
        const char *type = ts_node_type(node);
        if (strcmp("comment", type) != 0) {
            const std::string indent(depth * 2, ' ');
            std::cout << indent << type << ": ";

            std::cout << std::endl;
        }


        // 递归遍历子节点
        const uint32_t child_count = ts_node_child_count(node);
        for (uint32_t i = 0; i < child_count; i++) {
            TSNode child = ts_node_child(node, i);
            traverse_node(child, source, depth + 1);
        }
    }

    class CHeaderBaseVisitor {
    public:
        enum class CNodeType {
            TranslationUnit, // 根节点
            FunctionDefinition,
            FunctionDeclarator,
            ParameterList,
            ParameterDeclaration,
            CompoundStatement,
            Declaration,
            InitDeclarator,
            Identifier,
            TypeIdentifier,
            NumberLiteral,
            StringLiteral,
            IfStatement,
            ForStatement,
            ReturnStatement,
            BinaryExpression,
            CallExpression,
            Unknown,
            PreprocIfdef,
        };
        static const std::unordered_map<std::string, CNodeType> c_node_types;

        std::string source;

        static CNodeType getTSNodeType(const TSNode &node) {
            const auto type = std::string(ts_node_type(node));
            return c_node_types.at(type);
        }

        static void parse(const TSNode &node, const std::string &source) {
            CHeaderBaseVisitor visitor;
            visitor.source = source;
            visitor.visit(node);
        }

        void visit(const TSNode &node) {
            switch (getTSNodeType(node)) {
                case CNodeType::TranslationUnit:
                    visitTranslationUnit(node);
                    break;
                case CNodeType::PreprocIfdef:
                    visitPreprocIfdef(node);
                    break;
                case CNodeType::FunctionDefinition:
                    visitFunctionDefinition(node);
                    break;
                default:
                    break;
            }
        }

        void visitTranslationUnit(const TSNode &node) {
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
        }

        void visitPreprocIfdef(const TSNode &node) {
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
        }

        void visitFunctionDefinition(const TSNode &node) {
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
        }

        void visitFunctionDeclaration(const TSNode &node) {
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
        }
    };

    decltype(CHeaderBaseVisitor::c_node_types) CHeaderBaseVisitor::c_node_types = {
            {"translation_unit", CNodeType::TranslationUnit},
            {"function_definition", CNodeType::FunctionDefinition},
            {"function_declarator", CNodeType::FunctionDeclarator},
            {"parameter_list", CNodeType::ParameterList},
            {"parameter_declaration", CNodeType::ParameterDeclaration},
            {"compound_statement", CNodeType::CompoundStatement},
            {"declaration", CNodeType::Declaration},
            {"init_declarator", CNodeType::InitDeclarator},
            {"identifier", CNodeType::Identifier},
            {"type_identifier", CNodeType::TypeIdentifier},
            {"number_literal", CNodeType::NumberLiteral},
            {"string_literal", CNodeType::StringLiteral},
            {"if_statement", CNodeType::IfStatement},
            {"for_statement", CNodeType::ForStatement},
            {"return_statement", CNodeType::ReturnStatement},
            {"binary_expression", CNodeType::BinaryExpression},
            {"call_expression", CNodeType::CallExpression},
            {"preproc_ifdef", CNodeType::PreprocIfdef},
    };

    /// 预处理
    class CHeaderPreprocVisitor : public CHeaderBaseVisitor {
        std::unordered_map<std::string, std::string> preproc_map;
    public:
        static void parse(const TSNode &node, const std::string &source) {
            CHeaderPreprocVisitor visitor;
            visitor.source = source;
            visitor.visit(node);
        }

        void visitPreprocIfdef(const TSNode &node) {

            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
        }
    };

    class CHeaderVisitor : public CHeaderBaseVisitor {
    public:
        static CNodeType getTSNodeType(const TSNode &node) {
            const auto type = std::string(ts_node_type(node));
            return c_node_types.at(type);
        }

        static SemNode *parse(const TSNode &node, const std::string &source) {
            CHeaderVisitor visitor;
            visitor.source = source;
            return visitor.visit(node);
        }

        SemNode *visit(const TSNode &node) {
            switch (getTSNodeType(node)) {
                case CNodeType::TranslationUnit:
                    return visitTranslationUnit(node);
                case CNodeType::PreprocIfdef:
                    return visitPreprocIfdef(node);
                default:
                    return nullptr;
            }
        }

        SemNode *visitTranslationUnit(const TSNode &node) {
            const auto block = new BlockNode();
            const auto program = new ProgramNode(block);
            program->addSemNode(block);
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                block->push_back(visit(child));
            }
            return program;
        }

        SemNode* visitPreprocIfdef(const TSNode &node) {
            const size_t child_count = ts_node_child_count(node);
            for (uint32_t i = 0; i < child_count; ++i) {
                TSNode child = ts_node_child(node, i);
                visit(child);
            }
            return nullptr;
        }
    };

} // namespace Riddle


export namespace Riddle::header {

    auto parseCHead(const std::string &filePath) {
        namespace fs = std::filesystem;
        const auto source = readFile(filePath);
        TSParser *parser = ts_parser_new();
        ts_parser_set_language(parser, tree_sitter_c());
        TSTree *tree = ts_parser_parse_string(parser, nullptr, source.data(), source.size());
        const TSNode root_node = ts_tree_root_node(tree);
        CHeaderPreprocVisitor::parse(root_node, source);
        const auto node = CHeaderVisitor::parse(root_node, source);
        ts_tree_delete(tree);
        ts_parser_delete(parser);
        return node;
    }
} // namespace Riddle::header
