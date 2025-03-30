#ifndef LLVM_LIB_TARGET_TARCH_TARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_TARCH_TARCHTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheTArchTarget;

<<<<<<< HEAD:llvm/lib/Target/TArch/TArchTargetMachine.h
class TArchTargetMachine : public CodeGenTargetMachineImpl {
=======
class TArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;

>>>>>>> d811cf7c74de ([TArch] 10. Add TArchTargetMachine::getObjFileLowering):llvm/lib/Target/TArch/TArchTargetMachine.h
public:
  TArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_TARCH_TARCHTARGETMACHINE_H
