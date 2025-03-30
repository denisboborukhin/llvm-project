#ifndef LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHINFO_H
#define LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace TArchOp {
enum OperandType : unsigned {
  OPERAND_TARCHM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace TArchOp

} // end namespace llvm

#endif
