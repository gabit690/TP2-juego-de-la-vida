################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PuntoYcoma-TP2/Color.cpp \
../PuntoYcoma-TP2/Dibujante.cpp \
../PuntoYcoma-TP2/EasyBMP.cpp \
../PuntoYcoma-TP2/Energia.cpp \
../PuntoYcoma-TP2/Enfermero.cpp \
../PuntoYcoma-TP2/Informe.cpp \
../PuntoYcoma-TP2/Interfaz.cpp \
../PuntoYcoma-TP2/JuegoDeLaVida.cpp \
../PuntoYcoma-TP2/MapaDeBits.cpp \
../PuntoYcoma-TP2/Parcela.cpp \
../PuntoYcoma-TP2/Portal.cpp \
../PuntoYcoma-TP2/Tablero.cpp \
../PuntoYcoma-TP2/celula.cpp \
../PuntoYcoma-TP2/main.cpp 

OBJS += \
./PuntoYcoma-TP2/Color.o \
./PuntoYcoma-TP2/Dibujante.o \
./PuntoYcoma-TP2/EasyBMP.o \
./PuntoYcoma-TP2/Energia.o \
./PuntoYcoma-TP2/Enfermero.o \
./PuntoYcoma-TP2/Informe.o \
./PuntoYcoma-TP2/Interfaz.o \
./PuntoYcoma-TP2/JuegoDeLaVida.o \
./PuntoYcoma-TP2/MapaDeBits.o \
./PuntoYcoma-TP2/Parcela.o \
./PuntoYcoma-TP2/Portal.o \
./PuntoYcoma-TP2/Tablero.o \
./PuntoYcoma-TP2/celula.o \
./PuntoYcoma-TP2/main.o 

CPP_DEPS += \
./PuntoYcoma-TP2/Color.d \
./PuntoYcoma-TP2/Dibujante.d \
./PuntoYcoma-TP2/EasyBMP.d \
./PuntoYcoma-TP2/Energia.d \
./PuntoYcoma-TP2/Enfermero.d \
./PuntoYcoma-TP2/Informe.d \
./PuntoYcoma-TP2/Interfaz.d \
./PuntoYcoma-TP2/JuegoDeLaVida.d \
./PuntoYcoma-TP2/MapaDeBits.d \
./PuntoYcoma-TP2/Parcela.d \
./PuntoYcoma-TP2/Portal.d \
./PuntoYcoma-TP2/Tablero.d \
./PuntoYcoma-TP2/celula.d \
./PuntoYcoma-TP2/main.d 


# Each subdirectory must supply rules for building sources it contributes
PuntoYcoma-TP2/%.o: ../PuntoYcoma-TP2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


