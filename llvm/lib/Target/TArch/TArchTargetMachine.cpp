#include "TArchTargetMachine.h"
#include "TArch.h"
#include "TargetInfo/TArchTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTArchTarget() {
  RegisterTargetMachine<TArchTargetMachine> A(getTheTArchTarget());
}

TArchTargetMachine::TArchTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  TARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// TArch Code Generator Pass Configuration Options.
class TArchPassConfig : public TargetPassConfig {
public:
  TArchPassConfig(TArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    TARCH_DUMP_CYAN
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *TArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  TARCH_DUMP_CYAN
  return new TArchPassConfig(*this, PM);
}
