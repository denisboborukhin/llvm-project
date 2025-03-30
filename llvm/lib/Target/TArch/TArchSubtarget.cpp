#include "TArchSubtarget.h"
#include "TArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "tarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "TArchGenSubtargetInfo.inc"

TArchSubtarget::TArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : TArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  TARCH_DUMP_CYAN
}