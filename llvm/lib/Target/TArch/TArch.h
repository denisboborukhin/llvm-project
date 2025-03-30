#ifndef LLVM_LIB_TARGET_TArch_TArch_H
#define LLVM_LIB_TARGET_TArch_TArch_H

#include "MCTargetDesc/TArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define TARCH_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define TARCH_DUMP(Color) {}

#define TARCH_DUMP_RED TARCH_DUMP(llvm::raw_ostream::RED)
#define TARCH_DUMP_GREEN TARCH_DUMP(llvm::raw_ostream::GREEN)
#define TARCH_DUMP_YELLOW TARCH_DUMP(llvm::raw_ostream::YELLOW)
#define TARCH_DUMP_CYAN TARCH_DUMP(llvm::raw_ostream::CYAN)
#define TARCH_DUMP_MAGENTA TARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define TARCH_DUMP_WHITE TARCH_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class TArchTargetMachine;
class FunctionPass;

FunctionPass *createTArchISelDag(TArchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_TArch_TArch_H