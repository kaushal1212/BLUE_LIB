#-----------------------------------------------------------------------------
# Simple make file to support build and flash of executables
#
# Use: make [TARGET] [EXECUTABLE_NAME]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      all - Builds binary and elf files in project (links as well)
#      clean - Removes all generated files
#      flash - Flash binary file into target platform
#      erase - Performs Full chip erase
#
# executable name:
#     Ex.  make all TARGET=test_gpio
#
# Author: kaushal dekivadia
# Date:   july 28, 2021
#------------------------------------------------------------------------------

include source.mk

TARGET := 
OS = Linux
 
ifeq ($(OS),Windows)
    DELETE = del /f
else
    DELETE = rm -f
endif

BINPATH = ./$(TARGET).bin

LIB_PATH = -L /usr/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m/nofp

TEST_PATH = test/
# Architecture Specifications and flags

MARCH = armv7-m
CPU = cortex-m3

LINKERFILE = stm32f103xx.lds


#compilers flags and defines

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld.bfd
SIZE = arm-none-eabi-size
OBJCOPY = arm-none-eabi-objcopy


CFLAGS = -mcpu=$(CPU) -march=$(MARCH) -mthumb  -mfloat-abi=soft -std=c99 -Wall -O0 -g -MMD -fdata-sections -ffunction-sections


LDFLAGS = -Map=$(TARGET).map -T $(LINKERFILE) $(LIB_PATH) -lgcc  -o0 -lgcov --gc-sections
CPPFLAGS = -DSTM32F10X_MD $(INCLUDES) 

LOADER = st-flash



#object files

OBJS = $(SOURCES:.c=.o)    $(TEST_PATH)$(TARGET).o
ASMS = $(SOURCES:.c=.asm)  $(TEST_PATH)$(TARGET).asm
PREPS = $(SOURCES:.c=.i)   $(TEST_PATH)$(TARGET).i


#rules of building process

%.o:%.c
	$(CC) -c $^ $(CFLAGS) $(CPPFLAGS) -o $@

%.asm:%.c
	$(CC) -S $^ $(CFLAGS) $(CPPFLAGS) -o $@

%.i:%.c
	$(CC) -E $^ $(CPPFLAGS) -o $@

$(TEST_PATH)$(TARGET).elf:$(OBJS)
	$(LD) $(LDFLAGS)  $^ -o $@

$(TARGET).bin:$(TEST_PATH)$(TARGET).elf
	$(OBJCOPY) -O binary $^ $@

#build commands for makefile

all: $(TEST_PATH)$(TARGET).elf $(TARGET).bin

.PHONY: clean
clean:
	$(DELETE) src/*.o   src/*.d   $(TARGET).bin $(TEST_PATH)$(TARGET).elf $(TARGET).map $(TEST_PATH)*.o $(TEST_PATH)*.d src/*.asm src/*.i

.PHONY: erase
erase:
	$(LOADER)  erase

.PHONY: flash
flash:
	$(LOADER) write  $(BINPATH) 0x08000000 
