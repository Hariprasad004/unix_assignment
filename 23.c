#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  pid_t child_pid = fork();

  if (child_pid > 0) {
    sleep(50);
    printf("Child PID = %d", child_pid);
  } else
    exit(0);

  return 0;
}
