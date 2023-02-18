# list all files so they can be seen in the IDE
target_sources(${PROJECT_NAME}
  PUBLIC
  lwfsm_app.c
  lwfsm_app_model2.c
  lwfsm_app.h
  lwfsm_opts.h
  lwfsm_states.fsm
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
