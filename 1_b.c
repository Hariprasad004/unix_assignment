#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char **argv) {
    int f;
    int n, count = 0;
    char buf;
    f = open(argv[1], O_RDONLY);
    while((n = read(f, &buf, 1)) > 0) {
        if(buf == ' ') {
            count++;
        }
    }
    printf("\nTotal number of blanks = %d\n", count);
    return 0;
}
