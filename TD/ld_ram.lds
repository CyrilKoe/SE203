MEMORY {
  flash : ORIGIN = 0x80000000, LENGTH = 1M
  sram1 : ORIGIN = 0x20000000, LENGTH = 96k
  sram2 : ORIGIN = 0x10000000, LENGTH = 32k
}

SECTIONS {
  .text : { *(.text) } >sram1
  .data : { *(.data) } >sram1
  .rodata : { *(.rodata) } >sram1
  .bss : { *(.bss) *(COMMON) } >sram1
}

ENTRY(_start)
