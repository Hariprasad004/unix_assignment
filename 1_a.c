#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>

int main(int argc, char **argv) {
    FILE *f;
    int n, count = 0;
    char buf;
    f = fopen(argv[1], "r");
    while(!feof(f)) {
        buf = fgetc(f);
        if(buf == ' ') {
            count++;
        }
    }
    printf("\nTotal number of blanks = %d\n", count);
}

