################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/96OLEDI2C.c \
../User/AHT20.c \
../User/SerialPort.c \
../User/ch32v00x_it.c \
../User/main.c \
../User/system_ch32v00x.c 

OBJS += \
./User/96OLEDI2C.o \
./User/AHT20.o \
./User/SerialPort.o \
./User/ch32v00x_it.o \
./User/main.o \
./User/system_ch32v00x.o 

C_DEPS += \
./User/96OLEDI2C.d \
./User/AHT20.d \
./User/SerialPort.d \
./User/ch32v00x_it.d \
./User/main.d \
./User/system_ch32v00x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

