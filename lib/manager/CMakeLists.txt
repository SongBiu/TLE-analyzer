add_library(manager SHARED
    BlockManager.cpp
    LoopManager.cpp
)
target_link_libraries(manager util)