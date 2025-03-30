add_llvm_component_group(TArch)

set(LLVM_TARGET_DEFINITIONS TArch.td)

tablegen(LLVM TArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM TArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM TArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM TArchGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(TArchCommonTableGen)

add_llvm_target(TArchCodeGen
  TArchTargetMachine.cpp
  TArchRegisterInfo.cpp
  TArchInstrInfo.cpp
  TArchSubtarget.cpp
  TArchAsmPrinter.cpp
  TArchISelDagToDag.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  TArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  TArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
