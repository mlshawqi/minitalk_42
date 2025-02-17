#include "minitalk.h"


void	send_bits(pid_t pid, unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = octet >> i & 1;
		if(bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
	}
}

int main(int argc, char *argv[])
{
	pid_t   pid;
    int     i;

	if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        i = 0;
        while(argv[2][i] != '\0')
        {
            send_bits(pid, (unsigned char)(argv[2][i]));
            i++;
        }
        send_bits(pid, '\0');
    }
    return (0);
}
