#  Source files to this variable of make file (common for both )

 SOURCES = ./src/main.c \
 		   ./src/gpio.c \
 		   ./src/delay.c \
           ./src/system_stm32f10x.c  \
           ./src/startup_stm32f103.c 
  
INCLUDES = -I ./include/CMSIS \
           -I ./include/common \
           -I ./include/stm32
