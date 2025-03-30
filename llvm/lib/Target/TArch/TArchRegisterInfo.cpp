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
const MCPhysReg *
TArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  TARCH_DUMP_GREEN
  return CSR_TArch_SaveList;
}

BitVector TArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  TARCH_DUMP_GREEN
  TArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(TArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(TArch::R2);
  }
  return Reserved;
}

bool TArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool TArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  TARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register TArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  TARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? TArch::R2 : TArch::R1;
}

const uint32_t *
TArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  TARCH_DUMP_GREEN
  return CSR_TArch_RegMask;
}
