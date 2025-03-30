#ifndef LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCASMINFO_H
#define LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class TArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit TArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TARCH_MCTARGETDESC_TARCHMCASMINFO_H