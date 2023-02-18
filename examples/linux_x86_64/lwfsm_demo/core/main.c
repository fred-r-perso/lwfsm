/**
 * @file            main.c
 * @brief           LwFSM demo application
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
#define MAIN_APP_C
/* Add your own includes here */
#include "main.h"
#include "lwfsm.h"
#include "lwfsm_app.h"
#include <stdio.h>

uint32_t my_user_ctxt = 0;
uint32_t gButtonCnt = 0;

int main(void)
{
  printf("***** LwFSM demo project *****\r\n");

  /* Run the FSM task : programming model 1 */
  printf("Start with programming model 1\r\n");
  myAppTaskM1(&my_user_ctxt);

  /* Run the FSM task : programming model 2 */
  printf("Switch to programming model 2\r\n");
  my_user_ctxt = 0;
  gButtonCnt = 0;
  myAppTaskM2(&my_user_ctxt);

  printf("***** LwFSM demo project completed.*****\r\n");
}
