add_library(manager SHARED
    BlockManager.cpp
    LoopManager.cpp
    ModuleManager.cpp
)
target_link_libraries(manager util)