#include "TargetInfo/SimTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getSimTarget() {
  static Target SimTarget;
  return SimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSimTargetInfo() {
  RegisterTarget<Triple::Sim> X(getSimTarget(), "Sim", "Sim Instruction Set",
                                   "Sim");
}