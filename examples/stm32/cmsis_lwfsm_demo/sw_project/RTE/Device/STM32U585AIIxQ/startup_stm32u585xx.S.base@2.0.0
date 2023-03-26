/******************************************************************************
 * @file     startup_stm32u585xx.s
 * @brief    CMSIS Core Device Startup File for STM32U585xx Device
 * @version  V2.0.0
 * @date     14. March 2023
 ******************************************************************************/
/*
 * Copyright (c) 2023 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

                .syntax  unified
                .arch    armv8-m.main

                #define __INITIAL_SP     __StackTop
                #define __STACK_LIMIT    __StackLimit
                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                #define __STACK_SEAL     __StackSeal
                #endif

                .section .vectors
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                .long    __INITIAL_SP                       /*     Initial Stack Pointer */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    SecureFault_Handler                /*  -9 Secure Fault Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVC_Handler                        /*  -5 SVCall Handler */
                .long    DebugMon_Handler                   /*  -4 Debug Monitor Handler */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Interrupts */
                .long    WWDG_IRQHandler                    /*     Window WatchDog interrupt */
                .long    PVD_PVM_IRQHandler                 /*     PVD/PVM through EXTI Line detection interrupt */
                .long    RTC_IRQHandler                     /*     RTC non-secure interrupt */
                .long    RTC_S_IRQHandler                   /*     RTC secure interrupt */
                .long    TAMP_IRQHandler                    /*     Tamper non-secure interrupt */
                .long    RAMCFG_IRQHandler                  /*     RAMCFG global
                .long    FLASH_IRQHandler                   /*     FLASH non-secure global interrupt */
                .long    FLASH_S_IRQHandler                 /*     FLASH secure global interrupt */
                .long    GTZC_IRQHandler                    /*     Global TrustZone Controller interrupt */
                .long    RCC_IRQHandler                     /*     RCC non-secure global interrupt */
                .long    RCC_S_IRQHandler                   /*     RCC secure global interrupt */
                .long    EXTI0_IRQHandler                   /*     EXTI Line0 interrupt */
                .long    EXTI1_IRQHandler                   /*     EXTI Line1 interrupt */
                .long    EXTI2_IRQHandler                   /*     EXTI Line2 interrupt */
                .long    EXTI3_IRQHandler                   /*     EXTI Line3 interrupt */
                .long    EXTI4_IRQHandler                   /*     EXTI Line4 interrupt */
                .long    EXTI5_IRQHandler                   /*     EXTI Line5 interrupt */
                .long    EXTI6_IRQHandler                   /*     EXTI Line6 interrupt */
                .long    EXTI7_IRQHandler                   /*     EXTI Line7 interrupt */
                .long    EXTI8_IRQHandler                   /*     EXTI Line8 interrupt */
                .long    EXTI9_IRQHandler                   /*     EXTI Line9 interrupt */
                .long    EXTI10_IRQHandler                  /*     EXTI Line10 interrupt */
                .long    EXTI11_IRQHandler                  /*     EXTI Line11 interrupt */
                .long    EXTI12_IRQHandler                  /*     EXTI Line12 interrupt */
                .long    EXTI13_IRQHandler                  /*     EXTI Line13 interrupt */
                .long    EXTI14_IRQHandler                  /*     EXTI Line14 interrupt */
                .long    EXTI15_IRQHandler                  /*     EXTI Line15 interrupt */
                .long    IWDG_IRQHandler                    /*     IWDG global interrupt */
                .long    SAES_IRQHandler                    /*     Secure AES global interrupt */
                .long    GPDMA1_Channel0_IRQHandler         /*     GPDMA1 Channel 0 global interrupt */
                .long    GPDMA1_Channel1_IRQHandler         /*     GPDMA1 Channel 1 global interrupt */
                .long    GPDMA1_Channel2_IRQHandler         /*     GPDMA1 Channel 2 global interrupt */
                .long    GPDMA1_Channel3_IRQHandler         /*     GPDMA1 Channel 3 global interrupt */
                .long    GPDMA1_Channel4_IRQHandler         /*     GPDMA1 Channel 4 global interrupt */
                .long    GPDMA1_Channel5_IRQHandler         /*     GPDMA1 Channel 5 global interrupt */
                .long    GPDMA1_Channel6_IRQHandler         /*     GPDMA1 Channel 6 global interrupt */
                .long    GPDMA1_Channel7_IRQHandler         /*     GPDMA1 Channel 7 global interrupt */
                .long    ADC1_IRQHandler                    /*     ADC1 global interrupt */
                .long    DAC1_IRQHandler                    /*     DAC1 global interrupt */
                .long    FDCAN1_IT0_IRQHandler              /*     FDCAN1 interrupt 0 */
                .long    FDCAN1_IT1_IRQHandler              /*     FDCAN1 interrupt 1 */
                .long    TIM1_BRK_IRQHandler                /*     TIM1 Break interrupt */
                .long    TIM1_UP_IRQHandler                 /*     TIM1 Update interrupt */
                .long    TIM1_TRG_COM_IRQHandler            /*     TIM1 Trigger and Commutation interrupt */
                .long    TIM1_CC_IRQHandler                 /*     TIM1 Capture Compare interrupt */
                .long    TIM2_IRQHandler                    /*     TIM2 global interrupt */
                .long    TIM3_IRQHandler                    /*     TIM3 global interrupt */
                .long    TIM4_IRQHandler                    /*     TIM4 global interrupt */
                .long    TIM5_IRQHandler                    /*     TIM5 global interrupt */
                .long    TIM6_IRQHandler                    /*     TIM6 global interrupt */
                .long    TIM7_IRQHandler                    /*     TIM7 global interrupt */
                .long    TIM8_BRK_IRQHandler                /*     TIM8 Break interrupt */
                .long    TIM8_UP_IRQHandler                 /*     TIM8 Update interrupt */
                .long    TIM8_TRG_COM_IRQHandler            /*     TIM8 Trigger and Commutation interrupt */
                .long    TIM8_CC_IRQHandler                 /*     TIM8 Capture Compare interrupt */
                .long    I2C1_EV_IRQHandler                 /*     I2C1 Event interrupt */
                .long    I2C1_ER_IRQHandler                 /*     I2C1 Error interrupt */
                .long    I2C2_EV_IRQHandler                 /*     I2C2 Event interrupt */
                .long    I2C2_ER_IRQHandler                 /*     I2C2 Error interrupt */
                .long    SPI1_IRQHandler                    /*     SPI1 global interrupt */
                .long    SPI2_IRQHandler                    /*     SPI2 global interrupt */
                .long    USART1_IRQHandler                  /*     USART1 global interrupt */
                .long    USART2_IRQHandler                  /*     USART2 global interrupt */
                .long    USART3_IRQHandler                  /*     USART3 global interrupt */
                .long    UART4_IRQHandler                   /*     UART4 global interrupt */
                .long    UART5_IRQHandler                   /*     UART5 global interrupt */
                .long    LPUART1_IRQHandler                 /*     LPUART1 global interrupt */
                .long    LPTIM1_IRQHandler                  /*     LPTIM1 global interrupt */
                .long    LPTIM2_IRQHandler                  /*     LPTIM2 global interrupt */
                .long    TIM15_IRQHandler                   /*     TIM15 global interrupt */
                .long    TIM16_IRQHandler                   /*     TIM16 global interrupt */
                .long    TIM17_IRQHandler                   /*     TIM17 global interrupt */
                .long    COMP_IRQHandler                    /*     COMP1 and COMP2 through EXTI Lines interrupt */
                .long    OTG_FS_IRQHandler                  /*     USB OTG FS global interrupt */
                .long    CRS_IRQHandler                     /*     CRS global interrupt */
                .long    FMC_IRQHandler                     /*     FMC global interrupt */
                .long    OCTOSPI1_IRQHandler                /*     OctoSPI1 global interrupt */
                .long    PWR_S3WU_IRQHandler                /*     PWR wake up from Stop3 interrupt */
                .long    SDMMC1_IRQHandler                  /*     SDMMC1 global interrupt */
                .long    SDMMC2_IRQHandler                  /*     SDMMC2 global interrupt */
                .long    GPDMA1_Channel8_IRQHandler         /*     GPDMA1 Channel 8 global interrupt */
                .long    GPDMA1_Channel9_IRQHandler         /*     GPDMA1 Channel 9 global interrupt */
                .long    GPDMA1_Channel10_IRQHandler        /*     GPDMA1 Channel 10 global interrupt */
                .long    GPDMA1_Channel11_IRQHandler        /*     GPDMA1 Channel 11 global interrupt */
                .long    GPDMA1_Channel12_IRQHandler        /*     GPDMA1 Channel 12 global interrupt */
                .long    GPDMA1_Channel13_IRQHandler        /*     GPDMA1 Channel 13 global interrupt */
                .long    GPDMA1_Channel14_IRQHandler        /*     GPDMA1 Channel 14 global interrupt */
                .long    GPDMA1_Channel15_IRQHandler        /*     GPDMA1 Channel 15 global interrupt */
                .long    I2C3_EV_IRQHandler                 /*     I2C3 event interrupt */
                .long    I2C3_ER_IRQHandler                 /*     I2C3 error interrupt */
                .long    SAI1_IRQHandler                    /*     Serial Audio Interface 1 global interrupt */
                .long    SAI2_IRQHandler                    /*     Serial Audio Interface 2 global interrupt */
                .long    TSC_IRQHandler                     /*     Touch Sense Controller global interrupt */
                .long    AES_IRQHandler                     /*     AES global interrupt */
                .long    RNG_IRQHandler                     /*     RNG global interrupt */
                .long    FPU_IRQHandler                     /*     FPU global interrupt */
                .long    HASH_IRQHandler                    /*     HASH global interrupt */
                .long    PKA_IRQHandler                     /*     PKA global interrupt */
                .long    LPTIM3_IRQHandler                  /*     LPTIM3 global interrupt */
                .long    SPI3_IRQHandler                    /*     SPI3 global interrupt */
                .long    I2C4_ER_IRQHandler                 /*     I2C4 Error interrupt */
                .long    I2C4_EV_IRQHandler                 /*     I2C4 Event interrupt */
                .long    MDF1_FLT0_IRQHandler               /*     MDF1 Filter 0 global interrupt */
                .long    MDF1_FLT1_IRQHandler               /*     MDF1 Filter 1 global interrupt */
                .long    MDF1_FLT2_IRQHandler               /*     MDF1 Filter 2 global interrupt */
                .long    MDF1_FLT3_IRQHandler               /*     MDF1 Filter 3 global interrupt */
                .long    UCPD1_IRQHandler                   /*     UCPD1 global interrupt */
                .long    ICACHE_IRQHandler                  /*     Instruction cache global interrupt */
                .long    OTFDEC1_IRQHandler                 /*     OTFDEC1 global interrupt */
                .long    OTFDEC2_IRQHandler                 /*     OTFDEC2 global interrupt */
                .long    LPTIM4_IRQHandler                  /*     LPTIM4 global interrupt */
                .long    DCACHE1_IRQHandler                 /*     Data cache global interrupt */
                .long    ADF1_IRQHandler                    /*     ADF interrupt */
                .long    ADC4_IRQHandler                    /*     ADC4 (12bits) global interrupt */
                .long    LPDMA1_Channel0_IRQHandler         /*     LPDMA1 SmartRun Channel 0 global interrupt */
                .long    LPDMA1_Channel1_IRQHandler         /*     LPDMA1 SmartRun Channel 1 global interrupt */
                .long    LPDMA1_Channel2_IRQHandler         /*     LPDMA1 SmartRun Channel 2 global interrupt */
                .long    LPDMA1_Channel3_IRQHandler         /*     LPDMA1 SmartRun Channel 3 global interrupt */
                .long    DMA2D_IRQHandler                   /*     DMA2D global interrupt */
                .long    DCMI_PSSI_IRQHandler               /*     DCMI/PSSI global interrupt */
                .long    OCTOSPI2_IRQHandler                /*     OCTOSPI2 global interrupt */
                .long    MDF1_FLT4_IRQHandler               /*     MDF1 Filter 4 global interrupt */
                .long    MDF1_FLT5_IRQHandler               /*     MDF1 Filter 5 global interrupt */
                .long    CORDIC_IRQHandler                  /*     CORDIC global interrupt */
                .long    FMAC_IRQHandler                    /*     FMAC global interrupt */
                .long    LSECSSD_IRQHandler                 /*     LSECSSD global interrupt */

__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                ldr      r0, =__INITIAL_SP
                msr      psp, r0

                ldr      r0, =__STACK_LIMIT
                msr      msplim, r0
                msr      psplim, r0

                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                ldr      r0, =__STACK_SEAL
                ldr      r1, =0xFEF5EDA5U
                strd     r1,r1,[r0,#0]
                #endif

                bl       SystemInit

                ldr      r4, =__copy_table_start__
                ldr      r5, =__copy_table_end__

.L_loop0:
                cmp      r4, r5
                bge      .L_loop0_done
                ldr      r1, [r4]                /* source address */
                ldr      r2, [r4, #4]            /* destination address */
                ldr      r3, [r4, #8]            /* word count */
                lsls     r3, r3, #2              /* byte count */

.L_loop0_0:
                subs     r3, #4                  /* decrement byte count */
                ittt     ge
                ldrge    r0, [r1, r3]
                strge    r0, [r2, r3]
                bge      .L_loop0_0

                adds     r4, #12
                b        .L_loop0
.L_loop0_done:

                ldr      r3, =__zero_table_start__
                ldr      r4, =__zero_table_end__

.L_loop2:
                cmp      r3, r4
                bge      .L_loop2_done
                ldr      r1, [r3]                /* destination address */
                ldr      r2, [r3, #4]            /* word count */
                lsls     r2, r2, #2              /* byte count */
                movs     r0, 0

.L_loop2_0:
                subs     r2, #4                  /* decrement byte count */
                itt      ge
                strge    r0, [r1, r2]
                bge      .L_loop2_0

                adds     r3, #8
                b        .L_loop2
.L_loop2_done:

                bl       _start

                .fnend
                .size    Reset_Handler, . - Reset_Handler


/* The default macro is not used for HardFault_Handler
 * because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/* Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm


/* Default exception/interrupt handler */

                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SecureFault_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  DebugMon_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  WWDG_IRQHandler
                Set_Default_Handler  PVD_PVM_IRQHandler
                Set_Default_Handler  RTC_IRQHandler
                Set_Default_Handler  RTC_S_IRQHandler
                Set_Default_Handler  TAMP_IRQHandler
                Set_Default_Handler  RAMCFG_IRQHandler
                Set_Default_Handler  FLASH_IRQHandler
                Set_Default_Handler  FLASH_S_IRQHandler
                Set_Default_Handler  GTZC_IRQHandler
                Set_Default_Handler  RCC_IRQHandler
                Set_Default_Handler  RCC_S_IRQHandler
                Set_Default_Handler  EXTI0_IRQHandler
                Set_Default_Handler  EXTI1_IRQHandler
                Set_Default_Handler  EXTI2_IRQHandler
                Set_Default_Handler  EXTI3_IRQHandler
                Set_Default_Handler  EXTI4_IRQHandler
                Set_Default_Handler  EXTI5_IRQHandler
                Set_Default_Handler  EXTI6_IRQHandler
                Set_Default_Handler  EXTI7_IRQHandler
                Set_Default_Handler  EXTI8_IRQHandler
                Set_Default_Handler  EXTI9_IRQHandler
                Set_Default_Handler  EXTI10_IRQHandler
                Set_Default_Handler  EXTI11_IRQHandler
                Set_Default_Handler  EXTI12_IRQHandler
                Set_Default_Handler  EXTI13_IRQHandler
                Set_Default_Handler  EXTI14_IRQHandler
                Set_Default_Handler  EXTI15_IRQHandler
                Set_Default_Handler  IWDG_IRQHandler
                Set_Default_Handler  SAES_IRQHandler
                Set_Default_Handler  GPDMA1_Channel0_IRQHandler
                Set_Default_Handler  GPDMA1_Channel1_IRQHandler
                Set_Default_Handler  GPDMA1_Channel2_IRQHandler
                Set_Default_Handler  GPDMA1_Channel3_IRQHandler
                Set_Default_Handler  GPDMA1_Channel4_IRQHandler
                Set_Default_Handler  GPDMA1_Channel5_IRQHandler
                Set_Default_Handler  GPDMA1_Channel6_IRQHandler
                Set_Default_Handler  GPDMA1_Channel7_IRQHandler
                Set_Default_Handler  ADC1_IRQHandler
                Set_Default_Handler  DAC1_IRQHandler
                Set_Default_Handler  FDCAN1_IT0_IRQHandler
                Set_Default_Handler  FDCAN1_IT1_IRQHandler
                Set_Default_Handler  TIM1_BRK_IRQHandler
                Set_Default_Handler  TIM1_UP_IRQHandler
                Set_Default_Handler  TIM1_TRG_COM_IRQHandler
                Set_Default_Handler  TIM1_CC_IRQHandler
                Set_Default_Handler  TIM2_IRQHandler
                Set_Default_Handler  TIM3_IRQHandler
                Set_Default_Handler  TIM4_IRQHandler
                Set_Default_Handler  TIM5_IRQHandler
                Set_Default_Handler  TIM6_IRQHandler
                Set_Default_Handler  TIM7_IRQHandler
                Set_Default_Handler  TIM8_BRK_IRQHandler
                Set_Default_Handler  TIM8_UP_IRQHandler
                Set_Default_Handler  TIM8_TRG_COM_IRQHandler
                Set_Default_Handler  TIM8_CC_IRQHandler
                Set_Default_Handler  I2C1_EV_IRQHandler
                Set_Default_Handler  I2C1_ER_IRQHandler
                Set_Default_Handler  I2C2_EV_IRQHandler
                Set_Default_Handler  I2C2_ER_IRQHandler
                Set_Default_Handler  SPI1_IRQHandler
                Set_Default_Handler  SPI2_IRQHandler
                Set_Default_Handler  USART1_IRQHandler
                Set_Default_Handler  USART2_IRQHandler
                Set_Default_Handler  USART3_IRQHandler
                Set_Default_Handler  UART4_IRQHandler
                Set_Default_Handler  UART5_IRQHandler
                Set_Default_Handler  LPUART1_IRQHandler
                Set_Default_Handler  LPTIM1_IRQHandler
                Set_Default_Handler  LPTIM2_IRQHandler
                Set_Default_Handler  TIM15_IRQHandler
                Set_Default_Handler  TIM16_IRQHandler
                Set_Default_Handler  TIM17_IRQHandler
                Set_Default_Handler  COMP_IRQHandler
                Set_Default_Handler  OTG_FS_IRQHandler
                Set_Default_Handler  CRS_IRQHandler
                Set_Default_Handler  FMC_IRQHandler
                Set_Default_Handler  OCTOSPI1_IRQHandler
                Set_Default_Handler  PWR_S3WU_IRQHandler
                Set_Default_Handler  SDMMC1_IRQHandler
                Set_Default_Handler  SDMMC2_IRQHandler
                Set_Default_Handler  GPDMA1_Channel8_IRQHandler
                Set_Default_Handler  GPDMA1_Channel9_IRQHandler
                Set_Default_Handler  GPDMA1_Channel10_IRQHandler
                Set_Default_Handler  GPDMA1_Channel11_IRQHandler
                Set_Default_Handler  GPDMA1_Channel12_IRQHandler
                Set_Default_Handler  GPDMA1_Channel13_IRQHandler
                Set_Default_Handler  GPDMA1_Channel14_IRQHandler
                Set_Default_Handler  GPDMA1_Channel15_IRQHandler
                Set_Default_Handler  I2C3_EV_IRQHandler
                Set_Default_Handler  I2C3_ER_IRQHandler
                Set_Default_Handler  SAI1_IRQHandler
                Set_Default_Handler  SAI2_IRQHandler
                Set_Default_Handler  TSC_IRQHandler
                Set_Default_Handler  AES_IRQHandler
                Set_Default_Handler  RNG_IRQHandler
                Set_Default_Handler  FPU_IRQHandler
                Set_Default_Handler  HASH_IRQHandler
                Set_Default_Handler  PKA_IRQHandler
                Set_Default_Handler  LPTIM3_IRQHandler
                Set_Default_Handler  SPI3_IRQHandler
                Set_Default_Handler  I2C4_ER_IRQHandler
                Set_Default_Handler  I2C4_EV_IRQHandler
                Set_Default_Handler  MDF1_FLT0_IRQHandler
                Set_Default_Handler  MDF1_FLT1_IRQHandler
                Set_Default_Handler  MDF1_FLT2_IRQHandler
                Set_Default_Handler  MDF1_FLT3_IRQHandler
                Set_Default_Handler  UCPD1_IRQHandler
                Set_Default_Handler  ICACHE_IRQHandler
                Set_Default_Handler  OTFDEC1_IRQHandler
                Set_Default_Handler  OTFDEC2_IRQHandler
                Set_Default_Handler  LPTIM4_IRQHandler
                Set_Default_Handler  DCACHE1_IRQHandler
                Set_Default_Handler  ADF1_IRQHandler
                Set_Default_Handler  ADC4_IRQHandler
                Set_Default_Handler  LPDMA1_Channel0_IRQHandler
                Set_Default_Handler  LPDMA1_Channel1_IRQHandler
                Set_Default_Handler  LPDMA1_Channel2_IRQHandler
                Set_Default_Handler  LPDMA1_Channel3_IRQHandler
                Set_Default_Handler  DMA2D_IRQHandler
                Set_Default_Handler  DCMI_PSSI_IRQHandler
                Set_Default_Handler  OCTOSPI2_IRQHandler
                Set_Default_Handler  MDF1_FLT4_IRQHandler
                Set_Default_Handler  MDF1_FLT5_IRQHandler
                Set_Default_Handler  CORDIC_IRQHandler
                Set_Default_Handler  FMAC_IRQHandler
                Set_Default_Handler  LSECSSD_IRQHandler

                .end
