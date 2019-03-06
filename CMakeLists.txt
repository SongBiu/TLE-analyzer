cmake_minimum_required(VERSION 3.13)
project(analyzer)

set(LLVM_HOME /usr/local/opt/llvm)
set(MAXOS_SDK /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr)
include_directories(${MACOS_SDK}/include)
link_directories(${MACOS_SDK}/lib)

if(NOT DEFINED ENV{LLVM_DIR})
    set(ENV{LLVM_DIR} $ENV{LLVM_HOME}/lib/cmake/llvm)
endif()

# add llvm support
find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

# add my include support
include_directories(include)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(sample)
add_subdirectory(lib)
# add_subdirectory(src)
add_executable(analyzer main.cpp)
target_link_libraries(analyzer LLVM)