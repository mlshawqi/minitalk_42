#include "minitalk.h"

void signal_handler(int sig, siginfo_t *info, void *context)
{
    static unsigned char    c;
    static int    len;
    unsigned char bit;

    (void)context;
    (void)info;
    if (sig == SIGUSR1)
        bit = 0;
    else if (sig == SIGUSR2)
        bit = 1;
    c = (c << 1) | (bit & 1);
    len++;
    if(len == 8)
    {
        len = 0;
        if(c == '\0')
        {
            c = 0;
            return ;
        }
        ft_printf("%c", c);
        c = 0;
    }
} 

int main()
{
    struct sigaction sa;

    sa.sa_sigaction = signal_handler;  
    sa.sa_flags = SA_SIGINFO;
    ft_printf("%d\n", getpid());
    while(1)
    {
        sigaction(SIGUSR1, &sa, 0);
        sigaction(SIGUSR2, &sa, 0);
    }
    return (0);
}