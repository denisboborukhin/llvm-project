#include "TArchRegisterInfo.h"
#include "TArch.h"
#include "TArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "TArchGenRegisterInfo.inc"

TArchRegisterInfo::TArchRegisterInfo() : TArchGenRegisterInfo(TArch::R0) {
  TARCH_DUMP_GREEN
}