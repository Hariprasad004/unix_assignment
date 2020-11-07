#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int i,n,sum=0;
    pid_t pid;
    system("clear");
    printf("Enter n value:");
    scanf("%d",&n);
    pid=fork();
    if(pid==0)
    {
        printf("From child process\n");
        for(i=1;i<n;i+=2)
        {
            printf("%d\n",i);
            sum+=i;
        }
        printf("Odd sum:%d\n",sum);
    }
    else
    {
        printf("From process\n");
        for(i=0;i<n;i+=2)
        {
            printf("%d\n",i);
            sum+=i;
        }
        printf("Even sum:%d\n",sum);
    }
    return 0;
}
