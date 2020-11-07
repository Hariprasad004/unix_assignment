#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct flock fl = {F_UNLCK, SEEK_SET, 0, 100, 0};
    int fd;
    int fsize, offset;
    char buf[50];
    if((fd = open(argv[1], O_RDWR)) == -1) {
        perror("Cannot open file");
        exit(1);
    } 
    printf("File is NOT locked by any process\n");
    printf("Press ENTER to lock the file\n");
    printf("*************************************\n");
    getchar();

    fl.l_type = F_WRLCK;
    fl.l_pid = getpid();
    if(fcntl(fd, F_SETLK, &fl) == -1) {
        perror("Cannot set Exclusive lock\n");
        exit(1);
    }
    else if(fl.l_type != F_UNLCK) {
        printf("File has been Exclusive locked by process : %d\n", fl.l_pid);
    }
    else {
        printf("File is NOT locked\n");
    }
    printf("Press ENTER to release lock\n");
    getchar();
    fl.l_type = F_UNLCK;
    printf("File has been unlocked\n");

    fsize = lseek(fd, 0, SEEK_END);
    offset = fsize - 50;
    
    lseek(fd, offset, SEEK_SET);

    read(fd, buf, 50);
    printf("Last 50 bytes contents in file is \n");
    printf("*************************************\n");
    printf("%s\n", buf);
    return 0;
}