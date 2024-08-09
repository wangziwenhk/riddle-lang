#ifndef RIDDLE_LANGUAGE_SETUP_H
#define RIDDLE_LANGUAGE_SETUP_H

#include <functional>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include <string>
#include <unordered_map>

namespace Riddle {
    typedef std::unordered_map<std::string, std::unordered_map<std::string, std::function<llvm::Value *(llvm::IRBuilder<> &, llvm::Value *)>>> castMapTy;
    typedef std::unordered_map<std::string, std::unordered_map<llvm::Type *, std::unordered_map<llvm::Type *, std::function<llvm::Value *(llvm::IRBuilder<> &, llvm::Value *, llvm::Value *)>>>> binaryOpMapTeleTy;
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
    extern binaryOpMapTeleTy binaryOpMapTele;
    extern const std::unordered_map<std::string, std::function<llvm::Type *(llvm::IRBuilder<> &)>> SampleType;
}// namespace Riddle

#endif//RIDDLE_LANGUAGE_SETUP_H
