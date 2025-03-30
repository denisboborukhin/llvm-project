add_llvm_component_library(LLVMTArchDesc
  TArchMCTargetDesc.cpp
  TArchMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  TArchInfo

  ADD_TO_COMPONENT
  TArch
 )
