#ifndef LLVM_LIB_TARGET_TARCH_TARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_TARCH_TARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "TArchGenRegisterInfo.inc"

namespace llvm {

struct TArchRegisterInfo : public TArchGenRegisterInfo {
public:
  TArchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TARCH_TARCHREGISTERINFO_H