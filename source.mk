#  Source files to this variable of make file (common for both )

 SOURCES = ./src/gpio.c \
 		   ./src/delay.c \
           ./src/system_stm32f10x.c  \
           ./src/startup_stm32f103.c \
	   ./src/lcd_16x2.c \
	   ./src/spi.c \
       ./src/uart.c
  
INCLUDES = -I ./include/CMSIS \
           -I ./include/common \
           -I ./include/stm32 \
	   -I ./include/standard
