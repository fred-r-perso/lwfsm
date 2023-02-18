# list all files so they can be seen in the IDE
target_sources(${PROJECT_NAME}
  PUBLIC
  main.c
  main.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
