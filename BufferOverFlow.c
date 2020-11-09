#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint16_t SHIRT_VAL = 20;

int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("usage: BufferOverFlow <Item count> <Order name>\n");
    exit(EXIT_FAILURE);
  }
  char Customer[8];
  uint16_t count = atoi(argv[1]);
  uint16_t Val = SHIRT_VAL * count;

  
  strcpy(Customer, (argv[2]));
  
  
  printf("Total: %d\n", Val);


  return 0;
}
  
