#include "minitalk.h"

char    *binary;

void binaryToDecimal(char *binary)
{
    int decimal = 0;
    int i = 0;

    while (i < 8) 
    {
        decimal = decimal * 2 + (binary[i] - '0');
        i++;
    }
    free(binary);
    binary = ft_calloc(9, sizeof(char));
    ft_printf("%c", decimal);
}

void    fall_str(char c)
{
    int i;

    i = 0;
    if(binary[i] == '\0')
    {
        binary[i] = c;
        i++;
    }
    while(binary[i] != '\0')
    {
        if(i < 7 && binary[i + 1] == '\0')
        {
            binary[i + 1] = c;
            return ;
        }
        i++;
    }
}

void signal_handler(int sig)
{   
    // printf("--%s\n", binary);
    if (sig == SIGUSR1)
        fall_str('0');
    else if (sig == SIGUSR2)
        fall_str('1');
    if(ft_strlen(binary) == 8)
        binaryToDecimal(binary);
}

int main()
{
    pid_t pid;
    struct sigaction   sg;
    
    sg.sa_handler = signal_handler;
    sg.sa_flags = 0;
    if(binary == NULL)
        binary = ft_calloc(9, sizeof(char));
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
    pid = getpid();
    ft_printf("%d\n", pid);
    while(1) sleep(1);
    return (0);
}