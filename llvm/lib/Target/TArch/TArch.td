include "llvm/Target/Target.td"
include "TArchRegisterInfo.td"
include "TArchInstrInfo.td"

def TArchInstrInfo : InstrInfo;
def TArch : Target {
  let InstructionSet = TArchInstrInfo;
}
