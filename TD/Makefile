PROG = main

LINKER_SCRIPT = ld_ram.lds

SOURCES = main.c init.c
CRT0 = crt0.s
OBJECTS = $(SOURCES:%.c=%.o) $(CRT0:%.s=%.o)
DEPENDANCY = $(subst .c,.d,$(SOURCES))

CC = arm-none-eabi-gcc

CFLAGS = -Wall -Werror -g -O1
LDFLAGS = -T $(LINKER_SCRIPT)

LDLIBS = -nostdlib
TARGET_ARCH = -mthumb
TARGET_MACH = -mcpu=cortex-m4 -mthumb

all: $(PROG)

-include $(DEPENDANCY)
%.d: %.c
	$(CC) -M -MF $@ -MP $<

$(PROG): $(OBJECTS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm *.o
	rm *.d

.PHONY: startgdbserver
startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

.PHONY: debug
debug:
	arm-none-eabi-gdb main
