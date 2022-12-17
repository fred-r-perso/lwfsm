/**
 * \file            lwfsm_app_template.c
 * \brief           LwFSM application file
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

/* declare your FSM state C function prototypes here */
static uint32_t prv_initial_state(void * opaque_ctxt);
static uint32_t prv_intermediate_state(void * opaque_ctxt);
static uint32_t prv_final_state(void * opaque_ctxt);

/* declare your lwfsm context here */
static lwfsm_ctxt_t my_lwfsm_ctxt;

/* Declare your FSM states here */
LWFSM_STATES_START(my_fsm_states)
LWFSM_STATES_DECL(INIT_STATE)
LWFSM_STATES_DECL(INTER_STATE)
LWFSM_STATES_DECL(FINAL_STATE)
LWFSM_STATES_END(my_fsm_states)

/* Declare your FSM states log names here */
LWFSM_LOGS_NAME_START(my_states_names)
LWFSM_LOG_NAME_DECL("Initial State")
LWFSM_LOG_NAME_DECL("Intermediate State")
LWFSM_LOG_NAME_DECL("Final State")
LWFSM_LOGS_NAME_END(my_states_names)

/* Declare your FSM table here */
LWFSM_TABLE_START(my_state_machine)
LWFSM_TABLE_ENTRY(prv_initial_state)
LWFSM_TABLE_ENTRY(prv_intermediate_state)
LWFSM_TABLE_ENTRY(prv_final_state)
LWFSM_TABLE_END(my_state_machine)

/* FSM task entry point */
void myAppTaskM1(void * p_ctxt)
{
  lwfsm_status_t ret = lwfsm_init_state_machine(&my_lwfsm_ctxt, my_state_machine, my_states_names, INIT_STATE);

  if (LWFSM_OK == ret)
  {
    ret = lwfsm_run_state_machine(&my_lwfsm_ctxt, p_ctxt);
  }

  if (LWFSM_ERROR == ret)
  {
    /* implment your code here */
    while(1);
  }
}

/* Implement your FSM states here */
static uint32_t prv_initial_state(void * opaque_ctxt)
{
  while (gButtonCnt < 3)
  {
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
  		printf("gButtonCnt=%lu\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}
    /** Enter sleep mode.
     *  The CPU can be woken up by the EXTI interrupt or the SystTick interrupt.
     */
    HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
  }

  return INTER_STATE;
}

static uint32_t prv_intermediate_state(void * opaque_ctxt)
{
	while (gButtonCnt < 6)
	{
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
  		printf("gButtonCnt=%lu\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}
		/** Enter sleep mode.
		 *  The CPU can be woken up by the EXTI interrupt or the SystTick interrupt.
		 */
		HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	}

	return FINAL_STATE;
}

static uint32_t prv_final_state(void * opaque_ctxt)
{
	while (gButtonCnt < 11)
	{
  	if (gButtonCnt > *(uint32_t *)opaque_ctxt)
  	{
  		printf("gButtonCnt=%lu\r\n", gButtonCnt);
  		*(uint32_t *)opaque_ctxt = gButtonCnt;
  	}
		/** Enter sleep mode.
		 *  The CPU can be woken up by the EXTI interrupt or the SystTick interrupt.
		 */
		HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	}

  return LWFSM_STOP_SUCCESS;
}
