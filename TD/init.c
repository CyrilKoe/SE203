#include <stdint.h>
extern uint8_t _bss_start, _bss_end;

//Remplit .bss à 0 octet par octet
void init_bss()
{
  uint8_t *dst;
  for (dst = &_bss_start; dst < &_bss_end; dst++)
    *dst = 0;
}
