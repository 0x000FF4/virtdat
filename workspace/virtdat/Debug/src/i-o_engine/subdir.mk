################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/i-o_engine/DatabaseAbstr.cpp 

OBJS += \
./src/i-o_engine/DatabaseAbstr.o 

CPP_DEPS += \
./src/i-o_engine/DatabaseAbstr.d 


# Each subdirectory must supply rules for building sources it contributes
src/i-o_engine/%.o: ../src/i-o_engine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


