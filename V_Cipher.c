#include <stdio.h>
#include <stdlib.h>

int alph[26] = {0};
char *cipher;
char *DATA;

int main(int argc, char* argv[]){
  if(argc < 3) {
    printf("usage: V_Cipher <txt file> <key>\n");
    exit(EXIT_FAILURE);
  }
  //Open file and set file pointer then assign cipher
  FILE *fp = fopen(argv[1], "r");
  cipher = argv[2];

  //Verify file opened
  if (fp == NULL)
  {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  //Check file size and return pointer to the beginning.
  int sz;
  fseek(fp, 0L, SEEK_END);
  sz = ftell(fp);
  DATA = malloc(sz * sizeof(char));
  rewind(fp);

  //fill alph and DATA
  char c;
  for(int k = 0; k < sz; ++k) {
    c = fgetc(fp);
    DATA[k] = c;
    if(c < 97) continue;
    alph[c - 97]++;
  }

  printf("\nPlaintext: \n%s\n", DATA);
  printf("\nLetter usage:\n");
  for(int k = 0;k <  26; ++k) {
    printf("%c: %.3f%%\n", k + 65, (float)(alph[k] * 100)/sz);
  }
  fclose(fp);
  free(DATA);
  return 0;
}
