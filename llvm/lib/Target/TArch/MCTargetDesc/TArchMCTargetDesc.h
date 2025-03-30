#ifndef LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createTArchMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createTArchAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
} // namespace llvm

// Defines symbolic names for TArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "TArchGenRegisterInfo.inc"

// Defines symbolic names for the TArch instructions.
#define GET_INSTRINFO_ENUM
#include "TArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCTARGETDESC_H
