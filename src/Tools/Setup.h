#ifndef RIDDLE_LANGUAGE_SETUP_H
#define RIDDLE_LANGUAGE_SETUP_H

#include <functional>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include <string>
#include <unordered_map>

namespace Riddle {
    typedef std::unordered_map<std::string, std::unordered_map<std::string, std::function<llvm::Value *(
                                                                                    llvm::IRBuilder<> &, llvm::Value *)>>>
            castMapTy;
    const static castMapTy castMapTemplate = {
            {"int",
             {
                     {"float", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateSIToFP(value, builder.getFloatTy(), "IntToFloat");
                      }},
                     {"double", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateSIToFP(value, builder.getDoubleTy(), "IntToDouble");
                      }},
                     {"short", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateTrunc(value, builder.getInt16Ty(), "IntToShort");
                      }},
                     {"char", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateTrunc(value, builder.getInt8Ty(), "IntToChar");
                      }},
             }},
            {"float",

             {
                     {"int", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt32Ty(), "FloatToInt");
                      }},
                     {"short", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt16Ty(), "FloatToShort");
                      }},
                     {"char", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt8Ty(), "FloatToChar");
                      }},
                     {"double", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPExt(value, builder.getDoubleTy(), "FloatToDouble");
                      }},
             }},
            {"double",

             {
                     {"int", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt32Ty(), "DoubleToInt");
                      }},
                     {"short", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt16Ty(), "DoubleToShort");
                      }},
                     {"char", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPToSI(value, builder.getInt8Ty(), "DoubleToChar");
                      }},
                     {"float", [](llvm::IRBuilder<> &builder, llvm::Value *value) -> llvm::Value * {
                          return builder.CreateFPExt(value, builder.getFloatTy(), "DoubleToFloat");
                      }},
             }}};

    static const std::unordered_map<std::string, std::function<llvm::Value *(llvm::IRBuilder<> &, llvm::Value *, llvm::Value *)>> opMap = {
            {"", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return v2; }},
            {"+", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateAdd(v1, v2, "AddV"); }},
            {"-", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateSub(v1, v2, "SubV"); }},
            {"*", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateMul(v1, v2, "MulV"); }},
            {"/", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateFDiv(v1, v2, "DivV"); }},
            {"%", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateSRem(v1, v2, "ModV"); }},
            {"<<", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateShl(v1, v2, "ShlV"); }},
            {">>", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateAShr(v1, v2, "AShrV"); }},
            {">>>", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateLShr(v1, v2, "LShrV"); }},
            {"^", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateXor(v1, v2, "XorV"); }},
            {"&", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateAnd(v1, v2, "AndV"); }},
            {"&&", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateAnd(v1, v2, "LAndV"); }},
            {"|", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateOr(v1, v2, "OrV"); }},
            {"||", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateOr(v1, v2, "LOrV"); }},
            {">", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateICmpSGT(v1, v2, "cmpV"); }},
            {">=", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateICmpSGE(v1, v2, "cmpV"); }},
            {"<", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateICmpSLT(v1, v2, "cmpV"); }},
            {"<=", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) { return builder.CreateICmpSLE(v1, v2, "cmpV"); }},
            {"!=", [](llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2) {
                 if(v1->getType()->isFloatTy() || v1->getType()->isDoubleTy())
                     return builder.CreateFCmpUNE(v1, v2, "fne");
                 else
                     return builder.CreateICmpNE(v1, v2, "ne");
             }}};

    static const std::unordered_map<std::string, std::function<llvm::Type *(llvm::IRBuilder<> &)>> SampleType = {
            {"int", [](llvm::IRBuilder<> &Builder) { return Builder.getInt32Ty(); }},
            {"short", [](llvm::IRBuilder<> &Builder) { return Builder.getInt16Ty(); }},
            {"char", [](llvm::IRBuilder<> &Builder) { return Builder.getInt8Ty(); }},
            {"bool", [](llvm::IRBuilder<> &Builder) { return Builder.getInt1Ty(); }},
            {"double", [](llvm::IRBuilder<> &Builder) { return Builder.getDoubleTy(); }},
            {"float", [](llvm::IRBuilder<> &Builder) { return Builder.getFloatTy(); }},
    };
}// namespace Riddle

#endif//RIDDLE_LANGUAGE_SETUP_H
