#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void charatatime(char *);
int main() {
  int pid;
  if ((pid = fork()) < 0)
    printf("fork error\n");
  else if (pid == 0)
    charatatime("output from child\n");
  else
    charatatime("output from parent\n");
  exit(0);
}
static void charatatime(char *str) {
  char *ptr;
  int c;
  setbuf(stdout, NULL);
  for (ptr = str; (c = *ptr++) != 0;)
    putc(c, stdout);
}
