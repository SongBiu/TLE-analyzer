add_library(pass SHARED
    LoopFinder.cpp
    DefineAnalyzer.cpp
)
target_link_libraries(pass util)
# add_library(LoopFinder SHARED LoopFinder.cpp)
# add_library(DefineAnalyzer SHARED DefineAnalyzer.cpp)
# target_link_libraries(LoopFinder Util)
# target_link_libraries(DefineAnalyzer Util)