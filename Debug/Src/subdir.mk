################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/dac.c \
../Src/dac_player.c \
../Src/dma.c \
../Src/fatfs.c \
../Src/gpio.c \
../Src/hal_hack.c \
../Src/main.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/tim.c \
../Src/user_diskio.c 

OBJS += \
./Src/dac.o \
./Src/dac_player.o \
./Src/dma.o \
./Src/fatfs.o \
./Src/gpio.o \
./Src/hal_hack.o \
./Src/main.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/tim.o \
./Src/user_diskio.o 

C_DEPS += \
./Src/dac.d \
./Src/dac_player.d \
./Src/dma.d \
./Src/fatfs.d \
./Src/gpio.d \
./Src/hal_hack.d \
./Src/main.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/tim.d \
./Src/user_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/Users/jcala/Documents/SDG2/base3/Inc" -I"C:/Users/jcala/Documents/SDG2/base3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/jcala/Documents/SDG2/base3/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/jcala/Documents/SDG2/base3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/jcala/Documents/SDG2/base3/Middlewares/Third_Party/FatFs/src" -I"C:/Users/jcala/Documents/SDG2/base3/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


