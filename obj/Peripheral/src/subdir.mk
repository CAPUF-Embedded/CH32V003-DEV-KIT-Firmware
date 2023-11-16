################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_adc.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dbgmcu.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dma.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_exti.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_flash.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_gpio.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_i2c.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_iwdg.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_misc.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_opa.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_pwr.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_rcc.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_spi.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_tim.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_usart.c \
C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_wwdg.c 

OBJS += \
./Peripheral/src/ch32v00x_adc.o \
./Peripheral/src/ch32v00x_dbgmcu.o \
./Peripheral/src/ch32v00x_dma.o \
./Peripheral/src/ch32v00x_exti.o \
./Peripheral/src/ch32v00x_flash.o \
./Peripheral/src/ch32v00x_gpio.o \
./Peripheral/src/ch32v00x_i2c.o \
./Peripheral/src/ch32v00x_iwdg.o \
./Peripheral/src/ch32v00x_misc.o \
./Peripheral/src/ch32v00x_opa.o \
./Peripheral/src/ch32v00x_pwr.o \
./Peripheral/src/ch32v00x_rcc.o \
./Peripheral/src/ch32v00x_spi.o \
./Peripheral/src/ch32v00x_tim.o \
./Peripheral/src/ch32v00x_usart.o \
./Peripheral/src/ch32v00x_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32v00x_adc.d \
./Peripheral/src/ch32v00x_dbgmcu.d \
./Peripheral/src/ch32v00x_dma.d \
./Peripheral/src/ch32v00x_exti.d \
./Peripheral/src/ch32v00x_flash.d \
./Peripheral/src/ch32v00x_gpio.d \
./Peripheral/src/ch32v00x_i2c.d \
./Peripheral/src/ch32v00x_iwdg.d \
./Peripheral/src/ch32v00x_misc.d \
./Peripheral/src/ch32v00x_opa.d \
./Peripheral/src/ch32v00x_pwr.d \
./Peripheral/src/ch32v00x_rcc.d \
./Peripheral/src/ch32v00x_spi.d \
./Peripheral/src/ch32v00x_tim.d \
./Peripheral/src/ch32v00x_usart.d \
./Peripheral/src/ch32v00x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32v00x_adc.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_dbgmcu.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_dma.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dma.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_exti.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_exti.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_flash.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_gpio.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_i2c.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_iwdg.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_misc.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_misc.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_opa.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_opa.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_pwr.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_rcc.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_spi.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_spi.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_tim.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_tim.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_usart.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_usart.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v00x_wwdg.o: C:/Users/91998/Downloads/CH32V003EVT\ (1)/EVT/EXAM/SRC/Peripheral/src/ch32v00x_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Debug" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Core" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\GPIO\CH32V003-DEV-KIT-FIRMWARE\User" -I"C:\Users\91998\Downloads\CH32V003EVT (1)\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

