################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.c 

OBJS += \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.o 

C_DEPS += \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.o: ../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DHSI_VALUE=8000000' '-DLSI_VALUE=40000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=1' '-DINSTRUCTION_CACHE_ENABLE=0' '-DDATA_CACHE_ENABLE=0' -DSTM32F051x8 -c -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/STM32F0xx_HAL_Driver/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Core/Inc -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/RTOS2/Include -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/DSP/Include -I"/home/tester/Documents/GitHub/MicroFlex/stm32/StepMotor/Drivers/CMSIS" -I/home/arpoyda/STM32CubeIDE/RoboArm/StepMotor/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

