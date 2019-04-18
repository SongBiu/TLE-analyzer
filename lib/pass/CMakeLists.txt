add_library(pass SHARED
    LoopFinder.cpp
    DefineAnalyzer.cpp
)
target_link_libraries(pass util manager)