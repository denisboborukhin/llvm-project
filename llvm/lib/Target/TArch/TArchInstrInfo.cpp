#include "TArchInstrInfo.h"
#include "TArch.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "TArchGenInstrInfo.inc"

#define DEBUG_TYPE "TArch-inst-info"

TArchInstrInfo::TArchInstrInfo() : TArchGenInstrInfo() { TARCH_DUMP_GREEN }
