#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  char d[50];
  if (argc == 3) {
    bzero(d, sizeof(d));
    strcat(d, "touch ");
    strcat(d, argv[1]);
    strcat(d, " -r ");
    strcat(d, argv[2]);
    system(d);
  } else {
    printf("Invalid no. of input\n");
  }
}
