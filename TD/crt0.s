  .syntax unified
  .cpu cortex-m4
  .global _start
  .thumb

_start:
  ldr sp, stackptr
  bl init_bss
  bl main

_exit:
  b _exit

stackptr:
  .word _stackptr
