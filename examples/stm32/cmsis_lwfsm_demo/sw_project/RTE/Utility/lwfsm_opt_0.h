/**
 * @file            lwfsm_opt.h
 * @brief           LwFSM options
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
#ifndef LWFSM_HDR_OPT_H
#define LWFSM_HDR_OPT_H

/* Uncomment to ignore user options (or set macro in compiler flags) */
/* #define LWFSM_IGNORE_USER_OPTS */

/* Include application options */
#ifndef LWFSM_IGNORE_USER_OPTS
#include "lwfsm_opts.h"
#endif /* LWFSM_IGNORE_USER_OPTS */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup        LWFSM_OPT Configuration
 * @brief           Default configuration setup
 * @{
 */

/**
 * @brief           Enables `1` or disables `0` the logs
 *
 * It enables the logging mechanism (one log level only)
 */
#ifndef LWFSM_USE_LOG
#define LWFSM_USE_LOG 1 /*!< use logs by default */
#endif /* LWFSM_USE_LOG */

/**
 * @brief           Enables `1` or disables `0` the FSM context
 *
 * It enables the possibility to pass a context from one FSM state to another
 */
#ifndef LWFSM_USE_CONTEXT
#define LWFSM_USE_CONTEXT 1 /*!< use applicative context by default */
#endif /* LWFSM_USE_CONTEXT */

/**
 * @brief           Enables `1` or disables `0` the Programming Model 2
 *
 * It enables the possibility to have a single declaration of the FSM states
 */
#ifndef LWFSM_USE_PROGMOD2
#define LWFSM_USE_PROGMOD2 1 /*!< programming model 2 is available by default */
#endif /* LWFSM_USE_PROGMOD2 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWFSM_HDR_OPT_H */
