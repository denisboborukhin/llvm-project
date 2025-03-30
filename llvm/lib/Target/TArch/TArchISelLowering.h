#ifndef LLVM_LIB_TARGET_TARCH_TARCHISELLOWERING_H
#define LLVM_LIB_TARGET_TARCH_TARCHISELLOWERING_H

#include "TArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class TArchSubtarget;
class TArchTargetMachine;

namespace TArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace TArchISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TARCH_TARCHISELLOWERING_H