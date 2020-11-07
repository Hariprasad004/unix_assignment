#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char d[50];
  bzero(d, sizeof(d));
  strcat(d, "ls ");
  strcat(d, "-d ");
  strcat(d, "*/");
  system(d);
  return 0;
}
