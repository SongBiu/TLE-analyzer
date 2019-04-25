add_library(pass SHARED
    LoopFinder.cpp
    DefineAnalyzer.cpp
    BranchCutter.cpp
)
target_link_libraries(pass util manager)