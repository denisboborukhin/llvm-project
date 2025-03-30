add_llvm_component_group(TArch)

set(LLVM_TARGET_DEFINITIONS TArch.td)

tablegen(LLVM TArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TArchGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(TArchCommonTableGen)

add_llvm_target(TArchCodeGen
  TArchTargetMachine.cpp
  TArchRegisterInfo.cpp
  TArchInstrInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  TArchInfo

  ADD_TO_COMPONENT
  TArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
