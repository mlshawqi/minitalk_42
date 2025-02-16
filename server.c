#include "minitalk.h"

void signal_handler(int sig)
{
    static unsigned char    c;
    static int    len;
    unsigned char bit;

    if (sig == SIGUSR1)
        bit = 0;
    else if (sig == SIGUSR2)
        bit = 1;
    c = c | ( 1 << (7 - bit));
    len++;
    // ft_printf("Received bit: %d, c: %c, len: %d\n", bit, c, len);
    if(len == 8)
    {
        if(c == '\0')
            return ;
        ft_printf("%c", c);
        c = 0;
        len = 0;
    }
}

int main()
{
    ft_printf("%d\n", getpid());
    while(1)
    {
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
    }
    return (0);
}