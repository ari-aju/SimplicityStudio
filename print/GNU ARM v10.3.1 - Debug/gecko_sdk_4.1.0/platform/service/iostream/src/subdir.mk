################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_stdlib_config.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_uart.c \
C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_usart.c 

OBJS += \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream.o \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_retarget_stdio.o \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_stdlib_config.o \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_uart.o \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_usart.o 

C_DEPS += \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream.d \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_retarget_stdio.d \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_stdlib_config.d \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_uart.d \
./gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_usart.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream.c gecko_sdk_4.1.0/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_retarget_stdio.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.c gecko_sdk_4.1.0/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_retarget_stdio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_stdlib_config.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_stdlib_config.c gecko_sdk_4.1.0/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_stdlib_config.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_uart.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_uart.c gecko_sdk_4.1.0/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_uart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_usart.o: C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_usart.c gecko_sdk_4.1.0/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFR32MG12P433F1024GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\config" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print\autogen" -I"C:\Users\firmware-1\SimplicityStudio\v5_workspace\print" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/firmware-1/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.0/platform/service/iostream/src/sl_iostream_usart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


