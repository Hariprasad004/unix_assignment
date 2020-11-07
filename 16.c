#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  char d[50];
  if (argc == 2) {
    bzero(d, sizeof(d));
    strcat(d, "ls ");
    strcat(d, "-la ");
    strcat(d, argv[1]);
    strcat(d, "| ");
    strcat(d, "cut ");
    strcat(d, "-b ");
    strcat(d, "1-10");
    system(d);
  } else
    printf("\nInvalid No. of inputs");
  return 0;
}
