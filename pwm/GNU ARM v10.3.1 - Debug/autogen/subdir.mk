################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c 

OBJS += \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o 

C_DEPS += \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\pwm" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


