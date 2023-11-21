# CH32V003-DEV-KIT

CAPUF Embedded has released the CH32V003 Dev Kit to simplify developers’ lives.

If an engineer or maker wants to evaluate or start learning about CH32V003, they have an MCU breakout board, which is not very useful. They need different breakout boards for different interfaces to explore the MCU fully. CAPUF Embedded identified this gap and came up with the idea of building a more useful development board. That’s how the CH32V003 Dev Kit was born.

# What is this CH32V003 MCU?

The CH32V003 is an ultra-low-cost (10-cent) 32-bit microcontroller based on the RISC-V 2A core. It has a maximum system main frequency of 48MHz and features 2KB of SRAM and 16KB of Flash memory.

The CH32V003 also has a wide range of peripheral interfaces, including a DMA controller, a 10-bit ADC, an op-amp comparator, multiple timers, and standard communication interfaces such as USART, I2C, and SPI. The CH32V003 can be used in a wide range of applications.

[Read more about CH32V003](https://pallavaggarwal.in/2022/11/09/wch-riscv-microcontroller-ch32v003/)

## PCB TOP VIEW (3D) ##
![image](https://github.com/CAPUF-Embedded/CH32V003-DEV-KIT-Hardware/assets/13899090/a9e6eb04-1f70-4d22-9577-77ffd66e4d2c)

## PCB TOP VIEW (Actual board) ##
![image](https://github.com/CAPUF-Embedded/CH32V003-DEV-KIT-Hardware/assets/13899090/d4bed557-60c6-4af6-9b6d-9b4f471ec060)

CH32V003 Dev Kit Technical Features
- QFN20 Package CH32V003 MCU is used. This allows users to evaluate on the interfaces available on any package.
- USB-C Port for Power (5V) and Serial Interface
- On-board 3.3V LDO
- UART – USB to UART (CH340C)
- I2C – Temperature Humidity Sensor (AHT20/AHT20-F)
- I2C – Qwiik Connector for connecting external sensor boards
- I2C – 0.96″ 128×64 Pixels OLED Display Module (included in the package)
- I2C – 4 Pin Header is provided to connect to other boards via jumper wires. The connector is not soldered on the board.
- SPI – 8Mbit / 1MB SPI NOR Flash (Winbond 25Q80)
- PWM – RGB LED (5050)
- GPIO – I/P – Two Keys
- ADC I/P – 10k ohm Variable Resistor / Potentiometer
- GPIO – O/P – One LED and one Buzzer
- 3 Pin header for WCH-LinkE Programmer (3.3V, SWIO, GND)
- 2x 20 Pin headers for MCU IOs Breakout, dual row is for easy probing
- LED Indications for 5V/3.3V/UART RX, TX
- Option for connecting external 24Mhz Oscillator (by default, the jumper is disconnected)
- MCU Reset Button is provided on the board, which can also be used as a User Key if PD7 is configured for GPIO
