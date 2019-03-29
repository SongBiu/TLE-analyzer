add_executable(analyzer application.cpp ../lib/defineAnalyzer.cpp ../include/defineAnalyzer.h)
target_link_libraries(analyzer 
    LLVM 
    util
    loopFinder
    moduleManager
)