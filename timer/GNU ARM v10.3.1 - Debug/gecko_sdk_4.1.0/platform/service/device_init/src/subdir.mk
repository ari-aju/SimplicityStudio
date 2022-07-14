################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s1.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s1.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s1.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfxo_s1.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c 

OBJS += \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_emu_s1.o \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_nvic.o 

C_DEPS += \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_dcdc_s1.d \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_emu_s1.d \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_hfxo_s1.d \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_lfxo_s1.d \
./gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_nvic.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_dcdc_s1.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s1.c gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_dcdc_s1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_emu_s1.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s1.c gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_emu_s1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_hfxo_s1.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s1.c gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_hfxo_s1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_lfxo_s1.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfxo_s1.c gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_lfxo_s1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_nvic.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c gecko_sdk_4.1.0/platform/service/device_init/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\timer" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/device_init/src/sl_device_init_nvic.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


