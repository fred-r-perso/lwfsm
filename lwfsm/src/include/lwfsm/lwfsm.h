/**
 * \file            lwfsm.h
 * \brief           LwFSM API
 */

/*
 * Copyright (c) 2022 Frederic RUELLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of LwFSM - Lightweight FSM manager.
 *
 * Author:          Frederic RUELLE <frederic.ruelle@free.fr>
 * Version:         v0.1.0
 */
#ifndef LWFSM_HDR_API_H
#define LWFSM_HDR_API_H

#include <stdint.h>     /* lwfsm uses stddint types */
#include "lwfsm_opt.h"  /* lwfsm configuration      */
#include "lwfsm_log.h"  /* lwfsm log porting        */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * \defgroup        LWFSM FSM types
 * \brief           Types used to describe the Finite State Machine
 * \{
 */

/**
 * \brief           C function implementing a FSM state
 * \param           opaque_ctxt: an opaque context for the state (if LWFSM_USE_CONTEXT is enabled)
 * \return          the next FSM state
 *
 * Function implementing the logic a FSM state must run.
 */
#if LWFSM_USE_CONTEXT == 1
/* opaque context */
typedef uint32_t (*lwfsm_state_func_t)(void * opaque_ctxt);
#else
typedef uint32_t (*lwfsm_state_func_t)(void);
#endif /* LWFSM_USE_CONTEXT */

/**
 * \brief           FSM table row
 *
 * Structure describing one row in the FSM table
 */
typedef struct {
  lwfsm_state_func_t state_function; /*!< C function implementing the logic of an FSM state */
} lwfsm_table_row_t;


/**
 * \brief           Return value of the FSM run function
 *
 */
typedef enum {
  LWFSM_OK = 0,    /*!< The FSM state machine call succeeded */
  LWFSM_ERROR      /*!< The FSM state machine call encountered an error */
} lwfsm_status_t;


/**
 * \brief           Structure of the internal context of an FSM
 *
 */
typedef struct {
  const lwfsm_table_row_t *fsm_table; /*!< FSM table to be run */
  uint32_t cur_state;                  /*!< current FSM state */
#if LWFSM_USE_LOG == 1
  const char * *log_names;             /*!< array of log names for the FSM states */
#endif /* LWFSM_USE_LOG */
} lwfsm_ctxt_t;

/**
 * \brief           Structure of the internal context of an FSM
 *                  Programming Model 2
 */
typedef struct {
  const lwfsm_table_row_t *fsm_table; /*!< FSM table to be run */
  uint32_t cur_state;                  /*!< current FSM state */
#if LWFSM_USE_LOG == 1
  const char * *log_names;             /*!< array of log names for the FSM states */
#endif /* LWFSM_USE_LOG */
  uint32_t nb_states;                  /*!< number of FSM states */
} lwfsm_ctxt2_t;

/**
 * \}
 */

/**
 * \defgroup        LWFSM FSM Declaration macros
 * \brief           Macros used to describe the Finite State Machine
 * \{
 */

/**
 * \brief           Fake FSM state indicating to stop running the FSM (normal stop)
 *
 * We want to stop the FSM processing as we reached its expected termination point.
 */
#define LWFSM_STOP_SUCCESS 0xFFFFFFFEUL

/**
 * \brief           Fake FSM state indicating to stop running the FSM (error encountered)
 *
 * We want to stop the FSM processing as an unexpected error occurred.
 */
#define LWFSM_STOP_ERROR 0xFFFFFFFFUL

/**
 * \brief           Starts a new list of FSM states description
 *
 * It starts the description of the list of states.
 */
#define LWFSM_STATES_START(states_list) typedef enum {

/**
 * \brief           Declares a new FSM state - Model #1
 *
 * It adds a new state in the list of states.
 * /!\ The initial state must be the first one in this list. /!\
 *
 * See: lwfsm_app_model1_template.c
 */
#define LWFSM_STATES_DECL(fsm_state) fsm_state,

/**
 * \brief           Declares a new FSM state - Model #2
 *
 * It adds a new state in the FSM.
 * This macro must be redefined in the code depending on what is being defined:
 * list of states, list of state names, fsm table.
 *
 * See: lwfsm_app_model2_template.c
 *
 */
#define LWFSM_STATES_FULL_DECL(fsm_state, fsm_state_name, fsm_state_function) redefine_me_in_the_code

/**
 * \brief           Ends a new list of FSM states description
 *
 * It closes the description of the list of states.
 */
#define LWFSM_STATES_END(states_list) } lwfsm_##states_list##_t; /* FSM states */


/**
 * \brief           Starts a new FSM table description
 *
 * It starts the description of a Finite State Machine.
 */
#define LWFSM_TABLE_START(table_name) const lwfsm_table_row_t table_name[] = {

/**
 * \brief           Declares a new FSM state function - Model #1
 *
 * It declares a FSM state function in the FSM table.
 * /!\ The state functions must be added in the same order as the states declaration. /!\
 */
#define LWFSM_TABLE_ENTRY(state_function) {state_function},

/**
 * \brief           Closes a FSM table description
 *
 * It ends the description of a Finite State Machine.
 */
#define LWFSM_TABLE_END(table_name) };


/**
 * \brief           Starts a new list of FSM states log names description
 *
 * It starts the description of the list of log strings to be used for the FSM states.
 */
#define LWFSM_LOGS_NAME_START(states_log_names) const char * states_log_names[] = {

/**
 * \brief           Declares a new FSM state log name - Model #1
 *
 * It adds a new state in the list of states log names.
 * /!\ The state log name must be added in the same order as the states declaration. /!\
 */
#define LWFSM_LOG_NAME_DECL(fsm_state_name) fsm_state_name,

/**
 * \brief           Ends a new list of FSM states log names description
 *
 * It closes the description of log strings to be used for the FSM states.
 */
#define LWFSM_LOGS_NAME_END(states_log_names) };

/**
 * \}
 */


/**
 * \defgroup        LWFSM FSM engine
 * \brief           Functions to initialize and run a state machine
 * \{
 */

/**
 * \defgroup        LWFSM FSM engine Model 1
 * \brief           Functions to initialize and run a state machine
 * \{
 */

#if LWFSM_USE_LOG == 1
lwfsm_status_t lwfsm_init_state_machine(lwfsm_ctxt_t *fsm_ctxt, const lwfsm_table_row_t *fsm_table, const char * *states_log_names, const uint32_t initial_state);
#else
lwfsm_status_t lwfsm_init_state_machine(lwfsm_ctxt_t * fsm_ctxt, const lwfsm_table_row_t *fsm_table, const uint32_t initial_state);
#endif /* LWFSM_USE_LOG */

#if LWFSM_USE_CONTEXT == 1
lwfsm_status_t lwfsm_run_state_machine(lwfsm_ctxt_t * fsm_ctxt, void * user_ctxt);
#else
lwfsm_status_t lwfsm_run_state_machine(lwfsm_ctxt_t * fsm_ctxt);
#endif /* LWFSM_USE_CONTEXT */

/**
 * \}
 */

/**
 * Programming Model 2
 */
#if LWFSM_USE_PROGMOD2 == 1

/**
 * \defgroup        LWFSM FSM engine Model 2
 * \brief           Functions to initialize and run a state machine
 * \{
 */

#if LWFSM_USE_LOG == 1
lwfsm_status_t lwfsm_init_state_machineM2(lwfsm_ctxt2_t *fsm_ctxt, const lwfsm_table_row_t *fsm_table, const char * *states_log_names, const uint32_t initial_state, const uint32_t nb_states);
#else
lwfsm_status_t lwfsm_init_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt, const lwfsm_table_row_t *fsm_table, const uint32_t initial_state, const uint32_t nb_states);
#endif /* LWFSM_USE_LOG */

#if LWFSM_USE_CONTEXT == 1
lwfsm_status_t lwfsm_run_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt, void * user_ctxt);
#else
lwfsm_status_t lwfsm_run_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt);
#endif /* LWFSM_USE_CONTEXT */

#endif /* LWFSM_USE_PROGMOD2 */

/**
 * \}
 */

/**
 * \}
 */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWFSM_HDR_API_H */
