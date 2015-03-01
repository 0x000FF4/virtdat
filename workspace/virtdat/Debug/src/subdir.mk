################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/VirtColum.cpp \
../src/VirtualTable.cpp \
../src/VirtualTableMetadata.cpp \
../src/VritualIntegrityChecker.cpp \
../src/virtdat.cpp 

OBJS += \
./src/VirtColum.o \
./src/VirtualTable.o \
./src/VirtualTableMetadata.o \
./src/VritualIntegrityChecker.o \
./src/virtdat.o 

CPP_DEPS += \
./src/VirtColum.d \
./src/VirtualTable.d \
./src/VirtualTableMetadata.d \
./src/VritualIntegrityChecker.d \
./src/virtdat.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/boost/python/detail -I/home/x000ff4/Свалени/openssl-1.0.2/include -I/usr/include/python2.7 -I/home/x000ff4/Свалени/boost_1_57_0/boost/python/detail -O2 -g -Wall -c -fmessage-length=0 -std=c++11   -fPIC -c `wx-config --cxxflags`  -lstdc++ `wx-config --cxxflags` `wx-config --libs` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


