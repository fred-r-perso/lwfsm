cmake_minimum_required(VERSION 3.22)

# Debug message
message("Exiting ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")

# Register library to the system
add_library(lwfsm INTERFACE)
target_sources(lwfsm INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/lwfsm/lwfsm.c)
target_include_directories(lwfsm INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/include)

# Debug message
message("Exiting ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")
