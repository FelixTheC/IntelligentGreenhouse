################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/App/Src/commands.cpp \
../Core/App/Src/console.cpp 

OBJS += \
./Core/App/Src/commands.o \
./Core/App/Src/console.o 

CPP_DEPS += \
./Core/App/Src/commands.d \
./Core/App/Src/console.d 


# Each subdirectory must supply rules for building sources it contributes
Core/App/Src/%.o Core/App/Src/%.su Core/App/Src/%.cyclo: ../Core/App/Src/%.cpp Core/App/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-App-2f-Src

clean-Core-2f-App-2f-Src:
	-$(RM) ./Core/App/Src/commands.cyclo ./Core/App/Src/commands.d ./Core/App/Src/commands.o ./Core/App/Src/commands.su ./Core/App/Src/console.cyclo ./Core/App/Src/console.d ./Core/App/Src/console.o ./Core/App/Src/console.su

.PHONY: clean-Core-2f-App-2f-Src

