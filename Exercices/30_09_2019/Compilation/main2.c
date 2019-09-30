#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

const int x = 3; //.rodata
int y = 34;      //.data
int z;           //.bss

void fonction();

int main(int nb, char * argv[]){

  char nom[20] = "Cyril Koenig";
  char* a = malloc(sizeof(nom)); //tas
  *a = nom;

  printf("Addresse de x (rodata) = %x\n", (unsigned int) &x);
  printf("Addresse de y (data) = %x\n", (unsigned int) &y);
  printf("Addresse de z (bss) = %x\n", (unsigned int) &z);
  printf("Addresse de a (tas) = %x\n", (unsigned int) &a);
  fonction();
  return 0;
}

void fonction() {
  static int t = 1;
  t++;
  int b = 3; //pile
  printf("Addresse de b (n°%d) = %x\n", t,(unsigned int) &b);
  int c = 0;
  if(t < 3)
    fonction();
  return;
}
