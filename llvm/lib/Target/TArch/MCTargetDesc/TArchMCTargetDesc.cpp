#include "TArch.h"
#include "TargetInfo/TArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "TArchGenRegisterInfo.inc"

static MCRegisterInfo *createTArchMCRegisterInfo(const Triple &TT) {
  TARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitTArchMCRegisterInfo(X, TArch::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTArchTargetMC() {
  TARCH_DUMP_MAGENTA
  Target &TheTArchTarget = getTheTArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheTArchTarget, createTArchMCRegisterInfo);
}
