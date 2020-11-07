#include <stdio.h>
#include <sys/time.h>
#include <sys/signal.h>


void main();
int times_up();
void main()
{
    for (; ;)
    {
        times_up(1);
        sleep(60);
    }
}

int times_up(sig)
     int sig;
     {
       long now;
       long  time(struct tms *ptr);
       char *ctime();
       time (&now);
       printf("It is now %s\n", ctime (&now));
       return (sig);
     }
