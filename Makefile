#-----------------------------------------------------------------------------
#Simple make file to support two build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      all - Builds binary and elf files in project (links as well)
#      clean - Removes all generated files
#      flash - Flash binary file into target platform
#      erase - Performs Full chip erase
#
# Platform Overrides:
#     STM32F103C8T6 - Target cross-compiled platform
#
# Author: kaushal dekivadia
# Date:   july 28, 2021
#------------------------------------------------------------------------------

include source.mk

 TARGET := 
 OS = Windows
 


ifeq ($(OS),Windows)
 	Delete = del /f
else
    Delete = \rm -f
endif

 BINPATH = E:\BLUE_LIB_PROJECT\BLUE_LIB\$(TARGET).bin
# Architecture Specifications and flags

 MARCH = armv7-m
 CPU = cortex-m3

 LINKERFILE = stm32f103xx.lds

#compilers flags and defines

 CC = arm-none-eabi-gcc
 LD = arm-none-eabi-ld.bfd
 SIZE = arm-none-eabi-size
 OBJCOPY = arm-none-eabi-objcopy

 CFLAGS = -mcpu=$(CPU) -march=$(MARCH) -mthumb -mfloat-abi=soft -fsingle-precision-constant  -std=c99 -Wall -O0 -g -MMD
 LDFLAGS = -Map=$(TARGET).map -T $(LINKERFILE) -o0  
 CPPFLAGS = -DSTM32F10X_MD $(INCLUDES)

 LOADER = ST-LINK_CLI



#object files

 OBJS = $(SOURCES:.c=.o) $(TARGET).o
 ASMS = $(SOURCES:.c=.asm) $(TARGET).asm
 PREPS = $(SOURCES:.c=.i) $(TARGET).i


#rules of building process

%.o:%.c
	$(CC) -c $^ $(CFLAGS) $(CPPFLAGS) -o $@

%.asm:%.c
	$(CC) -S $^ $(CFLAGS) $(CPPFLAGS) -o $@

%.i:%.c
	$(CC) -E $^ $(CPPFLAGS) -o $@

$(TARGET).elf:$(OBJS)
	$(LD) $(LDFLAGS)  $^ -o $@

$(TARGET).bin:$(TARGET).elf
	$(OBJCOPY) -O binary $^ $@

#build commands for makefile

all: $(TARGET).elf $(TARGET).bin

.PHONY: clean
clean:
	$(Delete) src\*.o   src\*.d   $(TARGET).bin $(TARGET).elf $(TARGET).map $(TARGET).o $(TARGET).d src\*.asm src\*.i

.PHONY: erase
erase:
	$(LOADER) -ME

.PHONY: flash
flash:
	$(LOADER) -P $(BINPATH) 0x08000000 -V "after_programming" -Cksum $(BINPATH)

