PROG = main

LINKER_SCRIPT = ld_ram.lds

SOURCES = main.c init.c
CRT0 = crt0.s
OBJECTS = $(SOURCES:%.c=%.o) $(CRT0:%.s=%.o)
DEPENDANCY = $(subst .c,.d,$(SOURCES))

PREFIX = arm-linux-gnueabi
ifndef ubuntu
PREFIX = arm-none-eabi
endif

CC = $(PREFIX)-gcc
AS = $(CC)

CFLAGS = -Wall -Werror -g -O1
LDFLAGS = -T $(LINKER_SCRIPT) -Wl,--build-id=none
ASFLAGS = -c

LDLIBS = -nostdlib
TARGET_ARCH = -mthumb
TARGET_MACH = -mcpu=cortex-m4 -mthumb

all: $(PROG)

-include $(DEPENDANCY)
%.d: %.c
	$(CC) -M -MF $@ -MP $<

$(PROG): $(OBJECTS) $(LINKER_SCRIPT)
	$(LINK.c) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm *.o
	rm *.d

.PHONY: startgdbserver
startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

ifndef ubuntu
DB = $(PREFIX)-gdb
else
DB = gdb-multiarch
endif

.PHONY: debug
debug:
	 $(DB) main
