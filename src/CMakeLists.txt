add_executable(run Application.cpp)
target_link_libraries(run 
    analyzer
    # thread
)