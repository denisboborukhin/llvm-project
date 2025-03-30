add_llvm_component_group(TArch)

add_llvm_target(TArchCodeGen
  TArchTargetMachine.cpp

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
