################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../my_freeRTOS_blinky_proj/src/cr_startup_lpc175x_6x.c \
../my_freeRTOS_blinky_proj/src/my_code_freertos_blinky.c \
../my_freeRTOS_blinky_proj/src/sysinit.c 

OBJS += \
./my_freeRTOS_blinky_proj/src/cr_startup_lpc175x_6x.o \
./my_freeRTOS_blinky_proj/src/my_code_freertos_blinky.o \
./my_freeRTOS_blinky_proj/src/sysinit.o 

C_DEPS += \
./my_freeRTOS_blinky_proj/src/cr_startup_lpc175x_6x.d \
./my_freeRTOS_blinky_proj/src/my_code_freertos_blinky.d \
./my_freeRTOS_blinky_proj/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
my_freeRTOS_blinky_proj/src/%.o: ../my_freeRTOS_blinky_proj/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/home/navjot/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_chip_175x_6x/inc" -I"/home/navjot/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/navjot/Documents/MCUXpresso_11.1.1_3241/workspace/navjot_freeRTOS_blinky/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


