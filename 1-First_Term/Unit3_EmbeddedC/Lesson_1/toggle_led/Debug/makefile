################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
togle_led.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
togle_led.list \

OBJCOPY_HEX += \
togle_led.hex \

OBJCOPY_BIN += \
togle_led.bin \


# All Target
all: togle_led.elf secondary-outputs

# Tool invocations
togle_led.elf: $(OBJS) $(USER_OBJS) D:\Communication\02-embeded\ system\Lectures\unit_3\empeded_c\togle_led\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "togle_led.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Communication\02-embeded system\Lectures\unit_3\empeded_c\togle_led\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="togle_led.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

togle_led.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "togle_led.list"
	@echo 'Finished building: $@'
	@echo ' '

togle_led.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "togle_led.hex"
	@echo 'Finished building: $@'
	@echo ' '

togle_led.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "togle_led.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
