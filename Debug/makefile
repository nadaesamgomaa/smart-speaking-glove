################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Uart/Source/subdir.mk
-include MCAL/Dio/Source/subdir.mk
-include MCAL/Adc/Source/subdir.mk
-include HAL/Lcd/Source/subdir.mk
-include HAL/FlexSensor/Source/subdir.mk
-include HAL/CustomChar/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
Project.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Project.elf secondary-outputs

# Tool invocations
Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project.map -mmcu=atmega32 -o "Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

Project.lss: Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project.elf  >"Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project.elf
	-@echo ' '

post-build:
	-avr-objcopy -O ihex "Project.elf" "Project.hex"
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
