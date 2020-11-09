#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint16_t SHIRT_VAL = 20;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("usage: OverFlow <Shirt count>\n");
    exit(EXIT_FAILURE);
  }
  uint16_t count = atoi(argv[1]);
  uint16_t Val = SHIRT_VAL * count;

  
  printf("Total: %d\n", Val);


  return 0;
}
  
