_start = 0x20000000


MEMORY
{
  Flash (RX) : ORIGIN = 0x80000000, LENGTH = 1M
  SRAM1 (WX) : ORIGIN = 0x20000000, LENGTH = 96k
  SRAM2 (WX) : ORIGIN = 0x10000000, LENGTH = 32k
}

SECTIONS {
  .text : { *(.text) } >SRAM1
  .data : { *(.data) } >SRAM1
  .rodata : { *(.rodata) } >SRAM1
  .bss : { *(.bss) *(COMMON) } >SRAM1
}

ENTRY(start)
