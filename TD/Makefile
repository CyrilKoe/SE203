SOURC_C = main.c init.c
SOURC_S = crt0.s
OBJ_C = $(subst .c,.o,$(SOURC_C))
OBJ_S = $(subst .s,.o,$(SOURC_S))

LINKER_SCRIPT = ld_ram.lds

LINK_FLAGS = -nostdlib -T $(LINKER_SCRIPT)
C_FLAGS = -c -g -O1 -mcpu=cortex-m4 -mthumb
S_FLAGS = -mcpu=cortex-m4 -mthumb

CC = arm-none-eabi-gcc

all: prog

prog: $(OBJ_C) $(OBJ_S)
	$(CC) $(LINK_FLAGS) $(SOURC_C) $(SOURC_S) -o main

$(OBJ_C): %.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_S): %.o: %.s
	$(CC) $(S_FLAGS) -c $< -o $@

clean:
	rm *.o
	rm *.d

startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug:
	arm-none-eabi-gdb main
