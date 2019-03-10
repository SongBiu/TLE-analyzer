add_executable(analyzer main.cpp)
target_link_libraries(analyzer 
    LLVM 
    util
    loopFinder
    moduleManager
)