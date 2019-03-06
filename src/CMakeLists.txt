link_directories(../lib)
add_executable(analyzer main.cpp)
target_link_libraries(analyzer LLVM utils)