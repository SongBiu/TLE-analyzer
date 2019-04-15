add_library(manager SHARED
    BlockManager.cpp
    LoopManager.cpp
    ModuleManager.cpp
)
target_link_libraries(manager pass util)
# add_library(BlockManager SHARED BlockManager.cpp)
# add_library(LoopManager SHARED LoopManager.cpp)
# add_library(ModuleManager SHARED ModuleManager.cpp)
# target_link_libraries(BlockManager Util)
# target_link_libraries(ModuleManager LoopFinder DefineAnalyzer)