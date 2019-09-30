PROG = hello

SOURCES = main.c t1.c t2.c stubs.c
OBJECTS = $(subst .c,.o,$(SOURCES))
DEPENDANCY = $(subst .c,.d,$(SOURCES))

CC = arm-none-eabi-gcc

CFLAGS = -Wall -Werror -g -Og
LDFLAGS = -L/opt/mylibs

LDLIBS = -lm
TARGET_ARCH = -mthumb

VPATH = . ./libs

all: $(PROG)

stubs.o: CFLAGS = -g -O2

-include $(DEPENDANCY)
%.d: %.c
	$(CC) -M -MF $@ -MP $<

$(PROG): $(OBJECTS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm *.o
	rm *.d
