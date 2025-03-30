#include "TargetInfo/TArchTargetInfo.h"
#include "TArch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheTArchTarget() {
  static Target TheTArchTarget;
  return TheTArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTArchTargetInfo() {
  RegisterTarget<Triple::tarch> X(getTheTArchTarget(), "tarch",
                                "tarch target for LLVM course", "TArch");
}
