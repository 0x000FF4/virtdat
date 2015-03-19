################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/VirtualTable/VirtColum.o \
../src/VirtualTable/VirtualTable.o \
../src/VirtualTable/VirtualTableMetadata.o \
../src/VirtualTable/VritualIntegrityChecker.o 

CPP_SRCS += \
../src/VirtualTable/VirtColum.cpp \
../src/VirtualTable/VirtualTable.cpp \
../src/VirtualTable/VirtualTableMetadata.cpp \
../src/VirtualTable/VritualIntegrityChecker.cpp 

OBJS += \
./src/VirtualTable/VirtColum.o \
./src/VirtualTable/VirtualTable.o \
./src/VirtualTable/VirtualTableMetadata.o \
./src/VirtualTable/VritualIntegrityChecker.o 

CPP_DEPS += \
./src/VirtualTable/VirtColum.d \
./src/VirtualTable/VirtualTable.d \
./src/VirtualTable/VirtualTableMetadata.d \
./src/VirtualTable/VritualIntegrityChecker.d 


# Each subdirectory must supply rules for building sources it contributes
src/VirtualTable/%.o: ../src/VirtualTable/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/cairo -I/home/x000ff4/Свалени/rapidjson-master/include/ -I/usr/include/giomm-2.4/ -I/usr/include/gdkmm-3.0/ -I/usr/include/atkmm-1.6/ -I/usr/include/cairomm-1.0/ -I/usr/include/pangomm-1.4/pangomm/ -I/usr/include/cairomm-1.0/cairomm/ -I/usr/include/pangomm-1.4/ -I/usr/lib/x86_64-linux-gnu/pangomm-1.4/include/ -I/usr/lib/x86_64-linux-gnu/gdkmm-3.0/include/ -I/usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/sigc++-2.0/ -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glibmm-2.4/ -I/usr/include/gtkmm-3.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/boost/python/detail -I/usr/include/atk-1.0/ -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/cairo/ -I/usr/include/pango-1.0/ -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I/usr/include/glib-2.0/ -I/usr/include/gtk-3.0/ -I/home/x000ff4/Свалени/openssl-1.0.2/include -I/usr/include/python2.7 -I/home/x000ff4/Свалени/boost_1_57_0/boost/python/detail -O2 -g -Wall -c -fmessage-length=0 -std=c++11   `pkg-config  --cflags --libs gtk+-3.0` -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


