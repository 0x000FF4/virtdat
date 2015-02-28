################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InternetModule/ClientModule.cpp \
../src/InternetModule/MainServer.cpp \
../src/InternetModule/ServerModule.cpp 

OBJS += \
./src/InternetModule/ClientModule.o \
./src/InternetModule/MainServer.o \
./src/InternetModule/ServerModule.o 

CPP_DEPS += \
./src/InternetModule/ClientModule.d \
./src/InternetModule/MainServer.d \
./src/InternetModule/ServerModule.d 


# Each subdirectory must supply rules for building sources it contributes
src/InternetModule/%.o: ../src/InternetModule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/boost/python/detail -I/home/x000ff4/Свалени/openssl-1.0.2/include -I/usr/include/python2.7 -I/home/x000ff4/Свалени/boost_1_57_0/boost/python/detail -O2 -g -Wall -c -fmessage-length=0 -std=c++11   -fPIC `wx-config --cxxflags` `wx-config --libs` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


