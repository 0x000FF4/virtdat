################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/VirtColum.cpp \
../src/VirtualTable.cpp \
../src/virtdat.cpp 

OBJS += \
./src/VirtColum.o \
./src/VirtualTable.o \
./src/virtdat.o 

CPP_DEPS += \
./src/VirtColum.d \
./src/VirtualTable.d \
./src/virtdat.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


