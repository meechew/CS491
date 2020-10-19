#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cipher;
char *DATA;

void encrypt(char* txt, char* key) {
  ulong Ksz = strlen(key), Csz = strlen(txt);

  for(int k = 0; k < Csz; ++k) {
    if(txt[k] == '\n')
      continue;
    txt[k] +=  key[k%Ksz] - '`';
    if(txt[k] > 'z')
      txt[k] -= 26;
    if(txt[k] < 0)
      txt[k] += 230;
  }
}

void decrypt(char* txt, char* key) {
  ulong Ksz = strlen(key), Csz = strlen(txt);

  for(int k = 0; k < Csz; ++k) {
    if(txt[k] == '\n')
      continue;
    txt[k] -=  key[k%Ksz] - '`';
    if(txt[k] < 'a')
      txt[k] += 26;
  }
}

void CharUsage(char* str, int len) {
  int alph[26] = {0};
  for (int k = 0; k < len; ++k) {
    if(str[k] < 'a') continue;
    alph[str[k] - 'a']++;
  }
  printf("\nLetter usage:\n");
  for(int k = 0;k <  26; ++k) {
    printf("%c: %.3f%%\n", k + 65, (float)(alph[k] * 100)/len);
  }
}

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
  }
  fclose(fp);

  //Print data
  printf("\nPlaintext: \n%s\n", DATA);
  CharUsage(DATA, sz);

  //encrypt the plain text with the provided key
  encrypt(DATA, cipher);
  printf("\nEncrypted text: \n%s\n", DATA);
  CharUsage(DATA, sz);

  //decrypt the encrypted text with the provided key
  decrypt(DATA, cipher);
  printf("\nPlaintext: \n%s\n", DATA);

  free(DATA);
  return 0;
}
