################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.1.0/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.1.0/platform/service/system/src/subdir.mk
-include gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.1.0/platform/emlib/src/subdir.mk
-include gecko_sdk_4.1.0/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.1.0/platform/common/src/subdir.mk
-include gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := letimer
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: letimer.axf

# Tool invocations
letimer.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "C:\Users\firmware-1\SimplicityStudio\v5_workspace\letimer\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="letimer.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o letimer.axf -Wl,--start-group "./app.o" "./main.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.o" "./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.o" "./gecko_sdk_4.1.0/platform/common/src/sl_assert.o" "./gecko_sdk_4.1.0/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_core.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_emu.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_letimer.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_msc.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_system.o" "./gecko_sdk_4.1.0/platform/emlib/src/em_timer.o" "./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.1.0/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.1.0/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.1.0/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.1.0/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: letimer.hex'
	arm-none-eabi-objcopy -O ihex "letimer.axf" "letimer.hex"
	@echo ' '

	@echo 'Building bin file: letimer.bin'
	arm-none-eabi-objcopy -O binary "letimer.axf" "letimer.bin"
	@echo ' '

	@echo 'Building s37 file: letimer.s37'
	arm-none-eabi-objcopy -O srec "letimer.axf" "letimer.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "letimer.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) letimer.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
