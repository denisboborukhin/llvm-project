#ifndef LLVM_LIB_TARGET_TARCH_TARCHINSTRINFO_H
#define LLVM_LIB_TARGET_TARCH_TARCHINSTRINFO_H

#include "TArchRegisterInfo.h"
#include "MCTargetDesc/TArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "TArchGenInstrInfo.inc"

namespace llvm {

class TArchSubtarget;

class TArchInstrInfo : public TArchGenInstrInfo {
public:
  TArchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TARCH_TARCHINSTRINFO_H
