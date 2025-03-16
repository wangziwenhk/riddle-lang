module;
#include <llvm/Support/TargetSelect.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
export module Config.Init;
import Config.BasicOperator;
import Config.OperatorImpl;
export namespace Riddle::init {
    void init() {
        initBasicOpReType();
        initOperatorImpl();
        llvm::InitializeAllTargets();
        llvm::InitializeAllDisassemblers();
        llvm::InitializeAllAsmParsers();
        llvm::InitializeAllAsmPrinters();
        llvm::InitializeAllTargetMCs();
        llvm::InitializeAllTargetMCAs();
        llvm::InitializeAllTargetInfos();
    }
} // namespace Riddle::init
