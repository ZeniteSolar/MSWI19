################################################################################
# Makefile for AVR
#
# How to use:
# 	-Edit Project Settings
#	-This file should be at the root dir of the project
#	-install gcc-avr
#	The avr-libc from savannah doesn't support yet the atmega328pb. But the Atmel
#	distribution does it, so:
#	-install avr-libc from Atmel (aur: avr-libc-atmel )
#	-install Atmel 'ATmega Series Device Support' from http://packs.download.atmel.com/ (aur: avr-libc-atmel-atmega328pb )
#
# 	-Commans:
#		make				to compile
#		make clean	        to clean
#	-TODO:
#		make up				to upload
#		make doc			to generate docs w/ doxygen
#
################################################################################



################################################################################
################################################################################
################################################################################
########### Project Settings starts here

# project root dir
PRJDIR      :=  $(shell pwd)
# binaries (.elf and .hex)
BINDIR      :=  bin
# compiled object files
OBJDIR      :=  obj
# project documentation
DOCDIR		:=  doc
# libraries
LIBDIR      :=  lib
# .c sources files
SRCDIR      :=  src
# Project target and sources to be compiled
MAIN 		= 	main
# Define microcontroller settings
MCU 		?=	atmega328pb
F_CPU		?=	16000000UL
# Optimization
OPT			=	s
# Debug
DEBUG		=	dwarf-2
# documentation (auto generated)
DOXYFILE_MK	=	Doxyfile

########### Project Settings ends here
################################################################################
################################################################################
################################################################################



# These will automatically be checked if they are set to YES
SPECIAL_DEFS +=

TARGET = $(lastword $(subst /, ,$(CURDIR)))

SRCS	=	$(shell find $(SRCDIR) -type f -name \*.c)
OBJS	=	$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.c=.o))

SILENT ?= @
#CROSS ?= avr-
CROSS ?= ~/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-
ifneq ($(CROSS), )
	CC = $(CROSS)gcc
	CXX = $(CROSS)g++
	OBJCOPY = $(CROSS)objcopy
	OBJDUMP = $(CROSS)objdump
	SIZE = $(CROSS)size
endif

ifneq ($(F_CPU),)
 	CFLAGS += -DF_CPU=$(F_CPU)
endif

## Special defines

define CHECK_ANSWER
	ifeq ($$($(1)), YES)
   		CFLAGS += -D$(1)
	endif
endef

$(foreach i,$(SPECIAL_DEFS),$(eval $(call CHECK_ANSWER,$(i))))

##

#---------------- Compiler Options C ----------------
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#  -adhlns...:   create assembler listing
#  INFO: https://www.nongnu.org/avr-libc/user-manual/using_tools.html
CFLAGS += $(CDEFS)
CFLAGS += -O$(OPT)
CFLAGS += -g$(DEBUG)
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
CFLAGS += -mshort-calls
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -ffreestanding
CFLAGS += -mcall-prologues
#CFLAGS += --param inline-call-cost=2
#CFLAGS += -finline-limit=3
#CFLAGS += -fno-inline-small-functions
#CFLAGS += -fno-unit-at-a-time
CFLAGS += -Wundef
CFLAGS += -Wunreachable-code
CFLAGS += -Wsign-compare
CFLAGS += -Waddr-space-convert
CFLAGS += -Wmisspelled-isr
#CFLAGS += -Wa,-adhlns=$(<:%.c=$(OBJDIR)/%.lst)
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
CFLAGS += -mmcu=$(MCU)
CFLAGS += -std=gnu99
CFLAGS += -DF_CPU=$(F_CPU)
CFLAGS += -finput-charset=utf-8 -fexec-charset=iso-8859-15

CFLAGSALT += \
	-D__AVR_DEV_LIB_NAME__=m328pb

LDFLAGS = -Wl,-Map=$(OBJDIR)/$(TARGET).map,--cref
LDFLAGS += $(patsubst %,-L%,$(EXTRALIBDIRS))
#LDFLAGS += $(PRINTF_LIB) $(SCANF_LIB) 
LDFLAGS += $(MATH_LIB)
LDFLAGS += -static -Llib/avr-can-lib/src/ -lcan
#LDFLAGS += -static -Llib/DISPLAYS/SSD1306_AVR/ -lssd1306
LDFLAGS += -static -Llib/oled-display/ -loled-display

## Intel Hex file production flags
HEX_FLASH_FLAGS = \
	-R .eeprom \
	-R .fuse \
	-R .lock \
	-R .signature
HEX_EEPROM_FLAGS = \
	-j .eeprom \
	--set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings

.PHONY: directories doc

# all
all: directories $(TARGET).elf size 

# directories
directories: 
	$(SILENT) $(MKDIR_P) $(BINDIR) $(OBJDIR) $(DOCDIR) $(LIBDIR) $(SRCDIR)

# size
size: $(TARGET).elf
	$(SILENT) $(SIZE) -C --mcu=${MCU:b=} $(BINDIR)/$<

# clean
ifneq ($(wildcard $(OBJS) $(TARGET).elf $(TARGET).hex $(TARGET).eep $(TARGET).map $(OBJS:%.o=%.d=%.map) $(OBJS:%.o=%.lst=%.map)), )
clean: rmdoc
	-rm $(wildcard $(OBJS) $(TARGET).elf $(TARGET).hex $(TARGET).eep $(TARGET).map $(OBJS:%.o=%.d=%.map) $(OBJS:%.o=%.lst=%.map))
else
clean:
	@echo "Nothing to clean."
endif

MKDIR_P := mkdir -p

.SECONDARY:

## Link
%.elf: $(OBJS)
	@echo "Linking:" $@...
	@echo ""
	$(SILENT) $(CC) $(CFLAGSALT) $(CFLAGS) $(OBJS) -o $(BINDIR)/$@ $(LDFLAGS)

%.hex: $(BINDIR)/$(TARGET).elf 
	@echo "hex..:" $@
	@echo ""
	$(SILENT) $(OBJCOPY) -O ihex $(BINDIR)/$(TARGET).elf $(HEX_FLASH_FLAGS) $(BINDIR)/$@
 
## Compile
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "[$(TARGET)] Compiling:" $@...
	@echo ""
	$(SILENT) $(CC) $(CFLAGSALT) $(CFLAGS) -MMD -MF $(@:%.o=%.d) -c $< -o $@

$(OBJDIR)/%.d: $(SRCDIR)/%.c
	@echo "[$(TARGET)] Generating dependency:" $@...
	@echo ""
	$(SILENT) $(CC) $(CFLAGSALT) $(CFLAGS) -MM -MT $(addsuffix .o, $(basename $@)) -MF $@ $<

## Docs

# If makefile changes, maybe the list of sources has changed, so update doxygens list

doc: $(SRCS)
	@echo "Generating docs..."
	@echo ""
	$(SILENT) @mkdir -p $(DOCDIR)
	@echo $(cat $(DOXYFILE) ; echo INPUT = $(SRCDIR) ; echo PROJECT_NAME = $(shell basename $(PRJDIR))) | doxygen

rmdoc:
	@rm -rf doc
###############

## Programming

AVRDUDE := avrdude
AVRDUDE_PORT = /dev/ttyUSB0
AVRDUDE_SPEED = 115200
AVRDUDE_PROGRAMMER = arduino

AVRDUDE_FLAGS += -p $(MCU)
ifneq ($(AVRDUDE_PORT), )
  AVRDUDE_FLAGS += -P $(AVRDUDE_PORT)
endif
ifneq ($(AVRDUDE_PROGRAMMER), )
  AVRDUDE_FLAGS += -c $(AVRDUDE_PROGRAMMER)
endif
ifneq ($(AVRDUDE_SPEED), )
  AVRDUDE_FLAGS += -b $(AVRDUDE_SPEED)
endif

#Add more verbose output if we dont have SILENT set
ifeq ($(SILENT), )
  AVRDUDE_FLAGS += -v -v
endif

###############

# Check which .o files we already have and include their dependency files.
PRIOR_OBJS := $(wildcard $(OBJS))
include $(PRIOR_OBJS:%.o=%.d)
