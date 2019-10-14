MEMORY {
  flash : ORIGIN = 0x08000000, LENGTH = 1M
  sram1 : ORIGIN = 0x20000000, LENGTH = 96k
  sram2 : ORIGIN = 0x10000000, LENGTH = 32k
}

SECTIONS {
  .data : {
    *vector_table*
    *(.data)
  } > sram1
  .text : {
    *(.text)
  } > sram1
  .rodata : {
    *(.rodata)
  } > sram1
  .bss : {
    *(.bss) *(COMMON)
  } > sram1
}
_bss_start = ADDR(.bss);
_bss_end = ADDR(.bss) + SIZEOF(.bss);

_stackptr = ORIGIN(sram2)+LENGTH(sram2);

ENTRY(_start)
