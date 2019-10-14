PROG = main

LINKER_SCRIPT = ld_ram.lds

SOURCES = main.c init.c led.c uart.c matrix.c image.c
CRT0 = crt0.s
OBJECTS = $(SOURCES:%.c=%.o) $(CRT0:%.s=%.o) clocks.o raw_image.o
DEPENDANCY = $(subst .c,.d,$(SOURCES))

ifndef ubuntu
PREFIX = arm-none-eabi
DB = $(PREFIX)-gdb
else
PREFIX = arm-linux-gnueabi
DB = gdb-multiarch
endif


CC = $(PREFIX)-gcc
AS = $(CC)

CFLAGS =  -Wall -Werror -g -O1 -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T $(LINKER_SCRIPT) -Wl,--build-id=none
ASFLAGS = -c

LDLIBS = -nostdlib
TARGET_ARCH = -mcpu=cortex-m4 -mthumb
TARGET_MACH = -mcpu=cortex-m4 -mthumb

VPATH = . ./CMSIS/Device/ST/STM32L4xx/Include ./CMSIS/Include ./clocks ./Others

all: $(PROG)

-include $(DEPENDANCY)
%.d: %.c
	$(CC) -M -MF $@ -MP $<

$(PROG): $(OBJECTS) $(LINKER_SCRIPT)
	$(LINK.c) $^ $(LDLIBS) -o $@

raw_image.o: image.raw
	$(PREFIX)-objcopy -I binary -O elf32-littlearm -B arm $< $@

.PHONY: clean
clean:
	rm *.d
	rm *.o

.PHONY: startgdbserver
startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

.PHONY: debug
debug:
	 $(DB) main

.PHONY: tio
tio:
	tio -b 115200 -d 8 -s 1 -p none -f none /dev/ttyACM0
