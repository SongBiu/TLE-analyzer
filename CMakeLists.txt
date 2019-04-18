cmake_minimum_required(VERSION 3.13)

project(analyzer)
set(CMAKE_CXX_STANDARD 14)

# add llvm support
set(LLVM_HOME /usr/local/opt/llvm)
include_directories(${LLVM_HOME}/include)
link_directories(${LLVM_HOME}/lib)

# set my library
include_directories(${PROJECT_SOURCE_DIR}/include)
# link_libraries(${PROJECT_BINARY_DIR}/lib)

# set output path
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# other set
add_subdirectory(lib)
add_subdirectory(src)