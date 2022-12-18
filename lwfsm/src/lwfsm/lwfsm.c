/**
 * \file            lwfsm.c
 * \brief           LwFSM FSM engine
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
#define LWFSM_C

#include "lwfsm.h"

/**
 * \brief           FSM engine initialization
 * \param           fsm_ctxt: definition of the FSM to run, allocated by the caller (see @ref lwfsm_ctxt_t)
 * \param           fsm_table: the table of C functions implementing the FSM states logic
 * \param           states_log_names: FSM states names to be printed in the logs if LWFSM_USE_LOG is enabled
 * \param           initial_state: initial state of this FSM
 * \return          see @ref lwfsm_status_t
 */
#if LWFSM_USE_LOG == 1
lwfsm_status_t lwfsm_init_state_machine(lwfsm_ctxt_t * fsm_ctxt, const lwfsm_table_row_t * const fsm_table, const char ** states_log_names, const uint32_t initial_state)
#else
lwfsm_status_t lwfsm_init_state_machine(lwfsm_ctxt_t * fsm_ctxt, const lwfsm_table_row_t * const fsm_table, const uint32_t initial_state)
#endif /* LWFSM_USE_LOG */
{
#if LWFSM_USE_LOG == 1
  if ( (NULL == fsm_ctxt) || (NULL == fsm_table) || (NULL == states_log_names) )
#else
  if ( (NULL == fsm_ctxt) || (NULL == fsm_table) )
#endif /* LWFSM_USE_LOG */
  {
    LWFSM_LOG("[ERROR] LWFSM - NULL pointer(s).\r\n");
    return LWFSM_ERROR;
  }
  else
  {
    fsm_ctxt->cur_state = initial_state;
    fsm_ctxt->fsm_table = fsm_table;
#if LWFSM_USE_LOG == 1
    fsm_ctxt->log_names = states_log_names;
#endif /* LWFSM_USE_LOG */
    LWFSM_LOG("[INFO] LWFSM - init success.\r\n");
    return LWFSM_OK;
  }
}


/**
 * \brief           FSM engine loop
 * \param           fsm_ctxt: definition of the FSM to run (see @ref lwfsm_ctxt_t)
 * \param           user_ctxt: an opaque user context to be used in the FSM state functions
 * \return          see @ref lwfsm_status_t
 */
#if LWFSM_USE_CONTEXT == 1
lwfsm_status_t lwfsm_run_state_machine(lwfsm_ctxt_t * fsm_ctxt, void * user_ctxt)
#else
lwfsm_status_t lwfsm_run_state_machine(lwfsm_ctxt_t * fsm_ctxt)
#endif /* LWFSM_USE_CONTEXT */
{
  lwfsm_state_func_t state_func; /* next FSM state function to be called */
#if LWFSM_USE_LOG == 1
  const char * cur_state_name; /* name to be logged for the current state */
#endif /* LWFSM_USE_LOG */

  /* FSM engine loop */
  /* --------------- */
  while (fsm_ctxt->cur_state < LWFSM_STOP_SUCCESS)
  {
	/* Get current FSM state C function */
    state_func = fsm_ctxt->fsm_table[fsm_ctxt->cur_state].state_function;
#if LWFSM_USE_LOG == 1
    cur_state_name = fsm_ctxt->log_names[fsm_ctxt->cur_state];
    LWFSM_LOG("[INFO] LWFSM - entering state: %s\r\n", cur_state_name);
#endif /* LWFSM_USE_LOG */
    /* Run the state function */
#if LWFSM_USE_CONTEXT == 1
    fsm_ctxt->cur_state = state_func(user_ctxt);
#else
    fsm_ctxt->cur_state = state_func();
#endif /* LWFSM_USE_CONTEXT */
  }

  /* Manage return status */
  /* -------------------- */
  if (fsm_ctxt->cur_state == LWFSM_STOP_SUCCESS)
  {
    LWFSM_LOG("[INFO] LWFSM - FSM engine terminates with success.\r\n");
    return LWFSM_OK;
  }
  else
  {
    LWFSM_LOG("[ERROR] LWFSM - FSM engine terminates with an error.\r\n");
    return LWFSM_ERROR;
  }
}


/**
 * PROGRAMMING MODEL 2
 */
#if LWFSM_USE_PROGMOD2 == 1

/**
 * \brief           FSM engine initialization
 * \param           fsm_ctxt: definition of the FSM to run, allocated by the caller (see @ref lwfsm_ctxt_t)
 * \param           fsm_table: the table of C functions implementing the FSM states logic
 * \param           states_log_names: FSM states names to be printed in the logs if LWFSM_USE_LOG is enabled
 * \param           initial_state: initial state of this FSM
 * \param           nb_states: number of FSM states in the state machine
 * \return          see @ref lwfsm_status_t
 */
#if LWFSM_USE_LOG == 1
lwfsm_status_t lwfsm_init_state_machineM2(lwfsm_ctxt2_t *fsm_ctxt, const lwfsm_table_row_t *fsm_table, const char * *states_log_names, const uint32_t initial_state, const uint32_t nb_states)
#else
lwfsm_status_t lwfsm_init_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt, const lwfsm_table_row_t *fsm_table, const uint32_t initial_state, const uint32_t nb_states)
#endif /* LWFSM_USE_LOG */
{
#if LWFSM_USE_LOG == 1
  if ( (NULL == fsm_ctxt) || (NULL == fsm_table) || (NULL == states_log_names) )
#else
  if ( (NULL == fsm_ctxt) || (NULL == fsm_table) )
#endif /* LWFSM_USE_LOG */
  {
    LWFSM_LOG("[ERROR] LWFSM - NULL pointer(s).\r\n");
    return LWFSM_ERROR;
  }
  else
  {
    fsm_ctxt->cur_state = initial_state;
    fsm_ctxt->fsm_table = fsm_table;
#if LWFSM_USE_LOG == 1
    fsm_ctxt->log_names = states_log_names;
#endif /* LWFSM_USE_LOG */
    fsm_ctxt->nb_states = nb_states;
    LWFSM_LOG("[INFO] LWFSM - init success.\r\n");
    return LWFSM_OK;
  }
}


/**
 * \brief           FSM engine loop
 * \param           fsm_ctxt: definition of the FSM to run (see @ref lwfsm_ctxt_t)
 * \param           user_ctxt: an opaque user context to be used in the FSM state functions
 * \return          see @ref lwfsm_status_t
 */
#if LWFSM_USE_CONTEXT == 1
lwfsm_status_t lwfsm_run_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt, void * user_ctxt)
#else
lwfsm_status_t lwfsm_run_state_machineM2(lwfsm_ctxt2_t * fsm_ctxt)
#endif /* LWFSM_USE_CONTEXT */
{
  lwfsm_state_func_t state_func; /* next FSM state function to be called */
#if LWFSM_USE_LOG == 1
  const char * cur_state_name; /* name to be logged for the current state */
#endif /* LWFSM_USE_LOG */

  /* FSM engine loop */
  /* --------------- */
  while (fsm_ctxt->cur_state < fsm_ctxt->nb_states)
  {
	/* Get current FSM state C function */
    state_func = fsm_ctxt->fsm_table[fsm_ctxt->cur_state].state_function;
#if LWFSM_USE_LOG == 1
    cur_state_name = fsm_ctxt->log_names[fsm_ctxt->cur_state];
    LWFSM_LOG("[INFO] LWFSM - entering state: %s\r\n", cur_state_name);
#endif /* LWFSM_USE_LOG */
    /* Run the state function */
#if LWFSM_USE_CONTEXT == 1
    fsm_ctxt->cur_state = state_func(user_ctxt);
#else
    fsm_ctxt->cur_state = state_func();
#endif /* LWFSM_USE_CONTEXT */
  }

  /* Manage return status */
  /* -------------------- */
  if (fsm_ctxt->cur_state == LWFSM_STOP_SUCCESS)
  {
    LWFSM_LOG("[INFO] LWFSM - FSM engine terminates with success.\r\n");
    return LWFSM_OK;
  }
  else
  {
    LWFSM_LOG("[ERROR] LWFSM - FSM engine terminates with an error.\r\n");
    return LWFSM_ERROR;
  }
}

#endif /* LWFSM_USE_PROGMOD2 */

