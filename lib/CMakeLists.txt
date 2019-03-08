LINK_LIBRARIES(LLVM)
ADD_LIBRARY(util SHARED util.cpp)
ADD_LIBRARY(FunctionAnalyzer SHARED FunctionAnalyzer.cpp)
TARGET_LINK_LIBRARIES(FunctionAnalyzer util)