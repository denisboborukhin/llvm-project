include "llvm/Target/Target.td"
include "TArchRegisterInfo.td"
include "TArchInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def TArchInstrInfo : InstrInfo;
def TArch : Target {
  let InstructionSet = TArchInstrInfo;
}
