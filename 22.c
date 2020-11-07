#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void) {
  int pid;
  int status;
  printf("Hello World!\n");
  pid = fork();
  if (pid == -1) {
    perror("bad fork");
    exit(1);
  }
  if (pid == 0)
    printf("PID = %d I am the child process.\n", pid);
  else {
    wait(&status);
    printf("PID = %d I am the parent process.\n", pid);
  }
}
