add_llvm_component_library(LLVMTArchInfo
  TArchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  TArch
  )
