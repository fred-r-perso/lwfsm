/**
 * @file            lwfsm_app_template.c
 * @brief           LwFSM application file
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
#define LWFSM_APP_C
/* Add your own includes here */
#include "main.h"
#include "lwfsm.h"
#include "lwfsm_app.h"

/* emulate a user button on a physical board */
static void prv_key_press();

/* declare your FSM state C function prototypes here */
static uint32_t prv_initial_state(void * opaque_ctxt);
static uint32_t prv_intermediate_state(void * opaque_ctxt);
static uint32_t prv_final_state(void * opaque_ctxt);

/* declare your lwfsm context here */
static lwfsm_ctxt2_t my_lwfsm_ctxt;

/* Declare your FSM states here */
LWFSM_STATES_START(my_fsm_statesM2)
#undef LWFSM_STATES_FULL_DECL
#define LWFSM_STATES_FULL_DECL(fsm_state, fsm_state_name, fsm_state_function) fsm_state,
#include "lwfsm_states.fsm"
DUMMY_STATE /* Add a last element */
LWFSM_STATES_END(my_fsm_statesM2)

/* Declare your FSM states log names here */
LWFSM_LOGS_NAME_START(my_states_namesM2)
#undef LWFSM_STATES_FULL_DECL
#define LWFSM_STATES_FULL_DECL(fsm_state, fsm_state_name, fsm_state_function) fsm_state_name,
#include "lwfsm_states.fsm"
LWFSM_LOGS_NAME_END(my_states_namesM2)

/* Declare your FSM table here */
LWFSM_TABLE_START(my_state_machineM2)
#undef LWFSM_STATES_FULL_DECL
#define LWFSM_STATES_FULL_DECL(fsm_state, fsm_state_name, fsm_state_function) {fsm_state_function},
#include "lwfsm_states.fsm"
LWFSM_TABLE_END(my_state_machineM2)

/* Compute the number of FSM states */
#undef LWFSM_STATES_FULL_DECL

/* FSM task entry point */
void myAppTaskM2(void * p_ctxt)
{
  lwfsm_status_t ret = lwfsm_init_state_machineM2(&my_lwfsm_ctxt, my_state_machineM2, my_states_namesM2, (uint32_t)INIT_STATE, (uint32_t)DUMMY_STATE);

  if (LWFSM_OK == ret)
  {
    ret = lwfsm_run_state_machineM2(&my_lwfsm_ctxt, p_ctxt);
  }

  if (LWFSM_ERROR == ret)
  {
    /* implement your code here */
    while(1);
  }
}

/* Implement your FSM states here */
static uint32_t prv_initial_state(void * opaque_ctxt)
{
  while (gButtonCnt < 3U)
  {
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
      (void)printf("gButtonCnt=%u\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}

    /* Wait for a key press */
    prv_key_press();
  }

  return (uint32_t)INTER_STATE;
}

static uint32_t prv_intermediate_state(void * opaque_ctxt)
{
	while (gButtonCnt < 6U)
	{
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
  		(void)printf("gButtonCnt=%u\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}

    /* Wait for a key press */
    prv_key_press();
	}

	return (uint32_t)FINAL_STATE;
}

static uint32_t prv_final_state(void * opaque_ctxt)
{
	while (gButtonCnt < 11U)
	{
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
  		(void)printf("gButtonCnt=%u\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}

    /* Wait for a key press */
    prv_key_press();
	}

  return (uint32_t)LWFSM_STOP_SUCCESS;
}

static void prv_key_press()
{
  printf("Press a key to continue\n");
  printf("Press b to continue\n");
  while(getchar() != 'b'){}
  gButtonCnt++;
}
