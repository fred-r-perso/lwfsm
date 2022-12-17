/**
 * \file            lwfsm_log.h
 * \brief           LwFSM LOGions
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
#ifndef LWFSM_HDR_LOG_H
#define LWFSM_HDR_LOG_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \defgroup        LWFSM_LOG service
 * \brief           Default LOG service
 * \{
 */

/**
 * \brief           Logging service
 *
 * The default porting relies on the lib-C printf service.
 * It is up to the project to port this service to the targeted hardware.
 */
#if LWFSM_USE_LOG == 1
#ifndef LWFSM_LOG
#define LWFSM_LOG printf
#endif /* FSM_LOG */
#else
#define LWFSM_LOG(...)
#endif /* LWFSM_USE_LOG */

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWFSM_HDR_LOG_H */
