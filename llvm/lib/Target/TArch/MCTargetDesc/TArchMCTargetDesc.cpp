#include "MCTargetDesc/TArchInfo.h"
#include "TArch.h"
#include "TargetInfo/TArchTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "TArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "TArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "TArchGenSubtargetInfo.inc"

static MCRegisterInfo *createTArchMCRegisterInfo(const Triple &TT) {
  TARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitTArchMCRegisterInfo(X, TArch::R0);
  return X;
}

static MCInstrInfo *createTArchMCInstrInfo() {
  TARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitTArchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createTArchMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  TARCH_DUMP_MAGENTA
  return createTArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTArchTargetMC() {
  TARCH_DUMP_MAGENTA
  Target &TheTArchTarget = getTheTArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheTArchTarget, createTArchMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheTArchTarget, createTArchMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheTArchTarget,
                                          createTArchMCSubtargetInfo);
}
