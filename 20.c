#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  char d[50];
  char str[100];
  printf("\nEnter your command : ");
  gets(str);
  fflush(stdin);
  const char s[2] = " ";
  char *token;
  token = strtok(str, s);
  bzero(d, sizeof(d));
  while (token != NULL) {
    strcat(d, token);
    strcat(d, " ");
    token = strtok(NULL, s);
  }
  system(d);
}
