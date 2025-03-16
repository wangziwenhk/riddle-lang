module;
#include <llvm/Support/TargetSelect.h>
export module Config.Init;
import Config.BasicOperator;
import Config.OperatorImpl;
export namespace Riddle::init {
    void init() {
        initBasicOpReType();
        initOperatorImpl();

#ifdef RIDDLE_TARGET_X86
        LLVMInitializeX86Target();
        LLVMInitializeX86TargetInfo();
        LLVMInitializeX86TargetMC();
        LLVMInitializeX86AsmParser();
        LLVMInitializeX86AsmPrinter();
        LLVMInitializeX86Disassembler();
#endif
#ifdef RIDDLE_TARGET_ARM
        LLVMInitializeARMTarget();
        LLVMInitializeARMTargetInfo();
        LLVMInitializeARMTargetMC();
        LLVMInitializeARMAsmParser();
        LLVMInitializeARMAsmPrinter();
        LLVMInitializeARMDisassembler();
#endif
#ifdef RIDDLE_TARGET_AARCH64
        LLVMInitializeAArch64Target();
        LLVMInitializeAArch64TargetInfo();
        LLVMInitializeAArch64TargetMC();
        LLVMInitializeAArch64AsmParser();
        LLVMInitializeAArch64AsmPrinter();
        LLVMInitializeAArch64Disassembler();
#endif
#ifdef RIDDLE_TARGET_AMDGPU
        LLVMInitializeAMDGPUTarget();
        LLVMInitializeAMDGPUTargetInfo();
        LLVMInitializeAMDGPUTargetMC();
        LLVMInitializeAMDGPUAsmParser();
        LLVMInitializeAMDGPUAsmPrinter();
        LLVMInitializeAMDGPUDisassembler();
#endif
#ifdef RIDDLE_TARGET_AVR
        LLVMInitializeAVRTarget();
        LLVMInitializeAVRTargetInfo();
        LLVMInitializeAVRTargetMC();
        LLVMInitializeAVRAsmParser();
        LLVMInitializeAVRAsmPrinter();
        LLVMInitializeAVRDisassembler();
#endif
#ifdef RIDDLE_TARGET_BPF
        LLVMInitializeBPFTarget();
        LLVMInitializeBPFTargetInfo();
        LLVMInitializeBPFTargetMC();
        LLVMInitializeBPFAsmParser();
        LLVMInitializeBPFAsmPrinter();
        LLVMInitializeBPFDisassembler();
#endif
#ifdef RIDDLE_TARGET_HEXGON
        LLVMInitializeHexagonTarget();
        LLVMInitializeHexagonTargetInfo();
        LLVMInitializeHexagonTargetMC();
        LLVMInitializeHexagonAsmParser();
        LLVMInitializeHexagonAsmPrinter();
        LLVMInitializeHexagonDisassembler();
#endif
#ifdef RIDDLE_TARGET_LANAI
        LLVMInitializeLanaiTarget();
        LLVMInitializeLanaiTargetInfo();
        LLVMInitializeLanaiTargetMC();
        LLVMInitializeLanaiAsmParser();
        LLVMInitializeLanaiAsmPrinter();
        LLVMInitializeLanaiDisassembler();
#endif
#ifdef RIDDLE_TARGET_LOONGARCH
        LLVMInitializeLoongArchTarget();
        LLVMInitializeLoongArchTargetInfo();
        LLVMInitializeLoongArchTargetMC();
        LLVMInitializeLoongArchAsmParser();
        LLVMInitializeLoongArchAsmPrinter();
        LLVMInitializeLoongArchDisassembler();
#endif
#ifdef RIDDLE_TARGET_MIPS
        LLVMInitializeMipsTarget();
        LLVMInitializeMipsTargetInfo();
        LLVMInitializeMipsTargetMC();
        LLVMInitializeMipsAsmParser();
        LLVMInitializeMipsAsmPrinter();
        LLVMInitializeMipsDisassembler();
#endif
#ifdef RIDDLE_TARGET_MSP430
        LLVMInitializeMSP430Target();
        LLVMInitializeMSP430TargetInfo();
        LLVMInitializeMSP430TargetMC();
        LLVMInitializeMSP430AsmParser();
        LLVMInitializeMSP430AsmPrinter();
        LLVMInitializeMSP430Disassembler();
#endif
#ifdef RIDDLE_TARGET_NVPTX
        LLVMInitializeNVPTXTarget();
        LLVMInitializeNVPTXTargetInfo();
        LLVMInitializeNVPTXTargetMC();
        LLVMInitializeNVPTXAsmPrinter();
#endif
#ifdef RIDDLE_TARGET_POWERPC
        LLVMInitializePowerPCTarget();
        LLVMInitializePowerPCTargetInfo();
        LLVMInitializePowerPCTargetMC();
        LLVMInitializePowerPCAsmParser();
        LLVMInitializePowerPCAsmPrinter();
        LLVMInitializePowerPCDisassembler();
#endif
#ifdef RIDDLE_TARGET_RISCV
        LLVMInitializeRISCVTarget();
        LLVMInitializeRISCVTargetInfo();
        LLVMInitializeRISCVTargetMC();
        LLVMInitializeRISCVAsmParser();
        LLVMInitializeRISCVAsmPrinter();
        LLVMInitializeRISCVDisassembler();
#endif
#ifdef RIDDLE_TARGET_SPARC
        LLVMInitializeSparcTarget();
        LLVMInitializeSparcTargetInfo();
        LLVMInitializeSparcTargetMC();
        LLVMInitializeSparcAsmParser();
        LLVMInitializeSparcAsmPrinter();
        LLVMInitializeSparcDisassembler();
#endif
#ifdef RIDDLE_TARGET_SPIRV
        LLVMInitializeSPIRVTarget();
        LLVMInitializeSPIRVTargetInfo();
        LLVMInitializeSPIRVTargetMC();
        LLVMInitializeSPIRVAsmPrinter();
#endif
#ifdef RIDDLE_TARGET_SYSTEMZ
        LLVMInitializeSystemZTarget();
        LLVMInitializeSystemZTargetInfo();
        LLVMInitializeSystemZTargetMC();
        LLVMInitializeSystemZAsmParser();
        LLVMInitializeSystemZAsmPrinter();
        LLVMInitializeSystemZDisassembler();
#endif
#ifdef RIDDLE_TARGET_VE
        LLVMInitializeVETarget();
        LLVMInitializeVETargetInfo();
        LLVMInitializeVETargetMC();
        LLVMInitializeVEAsmParser();
        LLVMInitializeVEAsmPrinter();
        LLVMInitializeVEDisassembler();
#endif
#ifdef RIDDLE_TARGET_XCORE
        LLVMInitializeXCoreTarget();
        LLVMInitializeXCoreTargetInfo();
        LLVMInitializeXCoreTargetMC();
        LLVMInitializeXCoreAsmPrinter();
        LLVMInitializeXCoreDisassembler();
#endif
#ifdef RIDDLE_TARGET_WASM
        LLVMInitializeWebAssemblyTarget();
        LLVMInitializeWebAssemblyTargetInfo();
        LLVMInitializeWebAssemblyTargetMC();
        LLVMInitializeWebAssemblyAsmParser();
        LLVMInitializeWebAssemblyAsmPrinter();
        LLVMInitializeWebAssemblyDisassembler();
#endif
    }
} // namespace Riddle::init
