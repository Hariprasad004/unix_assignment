#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    FILE *f;
    f = fopen(argv[1], "r");
    if(f == NULL) {
        printf("File not found\n");
        exit(0);
    }
    int ch, wo, li;
    ch = wo = li = 0;
    char tmp;
    while((tmp = fgetc(f)) != EOF) {
        ch++;
        if(ch == '\n' || ch == '\0')
            li++;
        if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            wo++;
    }
    if(ch > 0) {
        wo++;
        li++;
    }
    printf("Total characters = %d\n", ch);
    printf("Total words = %d\n", wo);
    printf("Total lines = %d\n", li);
    return 0;
}
