################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/lwfsm/lwfsm/src/lwfsm/lwfsm.c 

OBJS += \
./lwfsm/src/lwfsm/lwfsm.o 

C_DEPS += \
./lwfsm/src/lwfsm/lwfsm.d 


# Each subdirectory must supply rules for building sources it contributes
lwfsm/src/lwfsm/lwfsm.o: C:/lwfsm/lwfsm/src/lwfsm/lwfsm.c lwfsm/src/lwfsm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../Core/Inc -I../App -I../../../../lwfsm/src/include/lwfsm -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -save-temps -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lwfsm-2f-src-2f-lwfsm

clean-lwfsm-2f-src-2f-lwfsm:
	-$(RM) ./lwfsm/src/lwfsm/lwfsm.d ./lwfsm/src/lwfsm/lwfsm.o ./lwfsm/src/lwfsm/lwfsm.su

.PHONY: clean-lwfsm-2f-src-2f-lwfsm

