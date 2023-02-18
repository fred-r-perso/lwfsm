cmake_minimum_required(VERSION 3.22)

project(lwfsm_demo)

# define the executable for this project: the target name is ${PROJECT_NAME}
add_executable(${PROJECT_NAME})

# get the sub-folders content
add_subdirectory(app)
add_subdirectory(core)

# use the lwfsm library
add_subdirectory(../../../lwfsm out)
target_link_libraries(${PROJECT_NAME} lwfsm)
