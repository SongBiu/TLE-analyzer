link_libraries(LLVM)
add_library(util SHARED Util.cpp)
add_subdirectory(pass)
add_subdirectory(manager)