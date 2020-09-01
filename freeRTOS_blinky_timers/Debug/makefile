################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include my_freeRTOS_blinky_timers/src/subdir.mk
-include freertos/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: freeRTOS_blinky_timers.axf

# Tool invocations
freeRTOS_blinky_timers.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/navjot/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_chip_175x_6x/Debug" -L"/home/navjot/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="freeRTOS_blinky_timers.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "freertos_blinky_Debug.ld" -o "freeRTOS_blinky_timers.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) freeRTOS_blinky_timers.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "freeRTOS_blinky_timers.axf"; # arm-none-eabi-objcopy -v -O binary "freeRTOS_blinky_timers.axf" "freeRTOS_blinky_timers.bin" ; # checksum -p LPC1769 -d "freeRTOS_blinky_timers.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
