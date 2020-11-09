#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int16_t SHIRT_VAL = 20;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("usage: UnderFlow <Shirt count>\n");
    exit(EXIT_FAILURE);
  }
  int16_t count = atoi(argv[1]);
  int16_t Val = SHIRT_VAL * (count * (-1));

  
  printf("Total: %d\n", Val);


  return 0;
}
  
