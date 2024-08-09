#include "Setup.h"
#include <filesystem>
#include <string>

namespace Riddle {

    binaryOpMapTeleTy binaryOpMapTele;

    const std::unordered_map<std::string, std::function<llvm::Type *(llvm::IRBuilder<> &)>> SampleType = {
            {"int", [](llvm::IRBuilder<> &Builder) { return Builder.getInt32Ty(); }},
            {"short", [](llvm::IRBuilder<> &Builder) { return Builder.getInt16Ty(); }},
            {"char", [](llvm::IRBuilder<> &Builder) { return Builder.getInt8Ty(); }},
            {"bool", [](llvm::IRBuilder<> &Builder) { return Builder.getInt1Ty(); }},
            {"double", [](llvm::IRBuilder<> &Builder) { return Builder.getDoubleTy(); }},
            {"float", [](llvm::IRBuilder<> &Builder) { return Builder.getFloatTy(); }},
    };


    void __attribute__((constructor)) initSetup() {
#define BOM_ARG llvm::IRBuilder<> &builder, llvm::Value *v1, llvm::Value *v2
        llvm::LLVMContext ctx;
        llvm::IRBuilder<> builder(ctx);
        for(const auto &[name, func]: SampleType) {
            llvm::Type *type = func(builder);
            binaryOpMapTele[""][type][type] = [](BOM_ARG) { return v2; };
            binaryOpMapTele["+"][type][type] = [](BOM_ARG) { return builder.CreateAdd(v1, v2, "AddV"); };
            binaryOpMapTele["-"][type][type] = [](BOM_ARG) { return builder.CreateSub(v1, v2, "SubV"); };
            binaryOpMapTele["*"][type][type] = [](BOM_ARG) { return builder.CreateMul(v1, v2, "MulV"); };
            binaryOpMapTele["/"][type][type] = [](BOM_ARG) { return builder.CreateFDiv(v1, v2, "DivV"); };
            binaryOpMapTele["%"][type][type] = [](BOM_ARG) { return builder.CreateSRem(v1, v2, "ModV"); };
            binaryOpMapTele["<<"][type][type] = [](BOM_ARG) { return builder.CreateShl(v1, v2, "ShlV"); };
            binaryOpMapTele[">>"][type][type] = [](BOM_ARG) { return builder.CreateAShr(v1, v2, "AShrV"); };
            binaryOpMapTele[">>>"][type][type] = [](BOM_ARG) { return builder.CreateLShr(v1, v2, "LShrV"); };
            binaryOpMapTele["^"][type][type] = [](BOM_ARG) { return builder.CreateXor(v1, v2, "XorV"); };
            binaryOpMapTele["&"][type][type] = [](BOM_ARG) { return builder.CreateAnd(v1, v2, "AndV"); };
            binaryOpMapTele["&&"][type][type] = [](BOM_ARG) { return builder.CreateAnd(v1, v2, "LAndV"); };
            binaryOpMapTele["|"][type][type] = [](BOM_ARG) { return builder.CreateOr(v1, v2, "OrV"); };
            binaryOpMapTele["||"][type][type] = [](BOM_ARG) { return builder.CreateOr(v1, v2, "LOrV"); };
            binaryOpMapTele[">"][type][type] = [](BOM_ARG) { return builder.CreateICmpSGT(v1, v2, "cmpV"); };
            binaryOpMapTele[">="][type][type] = [](BOM_ARG) { return builder.CreateICmpSGE(v1, v2, "cmpV"); };
            binaryOpMapTele["<"][type][type] = [](BOM_ARG) { return builder.CreateICmpSLT(v1, v2, "cmpV"); };
            binaryOpMapTele["<="][type][type] = [](BOM_ARG) { return builder.CreateICmpSLE(v1, v2, "cmpV"); };
            if(type == SampleType.at("double")(builder) || type == SampleType.at("float")(builder)) {
                binaryOpMapTele["!="][type][type] = [](BOM_ARG) { return builder.CreateFCmpUNE(v1, v2, "fne"); };
            } else {
                binaryOpMapTele["!="][type][type] = [](BOM_ARG) { return builder.CreateICmpNE(v1, v2, "ne"); };
            }
        }
#undef BOM_ARG
    }
}// namespace Riddle