################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Color.cpp \
../src/EasyBMP.cpp \
../src/Informe.cpp \
../src/Interfaz.cpp \
../src/MapaDeBits.cpp \
../src/Parcela.cpp \
../src/Tablero.cpp \
../src/celula.cpp \
../src/energia.cpp \
../src/main.cpp 

OBJS += \
./src/Color.o \
./src/EasyBMP.o \
./src/Informe.o \
./src/Interfaz.o \
./src/MapaDeBits.o \
./src/Parcela.o \
./src/Tablero.o \
./src/celula.o \
./src/energia.o \
./src/main.o 

CPP_DEPS += \
./src/Color.d \
./src/EasyBMP.d \
./src/Informe.d \
./src/Interfaz.d \
./src/MapaDeBits.d \
./src/Parcela.d \
./src/Tablero.d \
./src/celula.d \
./src/energia.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


