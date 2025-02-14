#include "minitalk.h"

void    my_fun()
{
    printf("hello hi\n");
}

int main()
{
    pid_t pid;
    struct sigaction   sg;
    
    sg.sa_sigaction = my_fun;
    sigaction(SIGUSR1, &sg, NULL);
    pid = getpid();
    printf("%d\n", pid);
    while(1) sleep(1);
    return (0);
}