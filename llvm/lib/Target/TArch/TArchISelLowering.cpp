#include "TArchISelLowering.h"
#include "TArch.h"
#include "TArchRegisterInfo.h"
#include "TArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "TArch-lower"

using namespace llvm;

TArchTargetLowering::TArchTargetLowering(const TargetMachine &TM,
                                     const TArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  TARCH_DUMP_RED
  addRegisterClass(MVT::i32, &TArch::GPRRegClass);
}

const char *TArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  TARCH_DUMP_RED
  switch (Opcode) {
  case TArchISD::CALL:
    return "TArchISD::CALL";
  case TArchISD::RET:
    return "TArchISD::RET";
  }
  return nullptr;
}
