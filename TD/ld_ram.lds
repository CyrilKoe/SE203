MEMORY {
  flash : ORIGIN = 0x08000000, LENGTH = 1M
  sram1 : ORIGIN = 0x20000000, LENGTH = 96k
  sram2 : ORIGIN = 0x10000000, LENGTH = 32k
}

SECTIONS {
  .text : {
    _text_start = . ;
    *(.text)
    _text_end = . ;
    } > sram1
  .data : {
    _data_start = . ;
    *(.data)
    _data_end = . ;
     } > sram1
  .rodata : { *(.rodata) } >sram1
  .bss : {
    _bss_start = . ;
    *(.bss) *(COMMON)
    _bss_end = . ;
    } > sram1
}
_stackptr = ORIGIN(sram2)+LENGTH(sram2);
ENTRY(_start)
