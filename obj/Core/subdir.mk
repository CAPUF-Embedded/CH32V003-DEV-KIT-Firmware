################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/core_riscv.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

