add_executable(analyzer application.cpp)
target_link_libraries(analyzer 
    LLVM 
    util
    loopFinder
    moduleManager
)