################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c 

OBJS += \
./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.o \
./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.o 

C_DEPS += \
./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.d \
./gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.c gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_BOARD_NAME="BRD4172A"' '-DSL_BOARD_REV="A00"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/startup_efr32mg12p.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_BOARD_NAME="BRD4172A"' '-DSL_BOARD_REV="A00"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\empty" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


