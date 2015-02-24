################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InternetModule/MainServer.cpp 

OBJS += \
./src/InternetModule/MainServer.o 

CPP_DEPS += \
./src/InternetModule/MainServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/InternetModule/%.o: ../src/InternetModule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -std=c++11  -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


