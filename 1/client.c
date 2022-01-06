# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>

typedef struct sigaction t_sigaction;

char		*str;
pid_t		pid;
t_sigaction act;
t_sigaction act2;

void send_data()
{
	if (str && *str)
	{
		if (*(str++) == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error 2", 7);
				exit(EXIT_FAILURE);
			}
		}	
		else if (kill(pid, SIGUSR2) == -1)
		{
			write(2, "Error 2", 7);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(1, "Success\n", 8);
		exit(EXIT_SUCCESS);
	}
	
}
/*void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		kill()
	}
}*/

void success()
{
	write(1, "Success\n", 8);
	exit(EXIT_SUCCESS);
}

void first_send()
{
	if (str && *str)
	{
		if (*(str++) == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error 2", 7);
				exit(EXIT_FAILURE);
			}
		}	
		else if (kill(pid, SIGUSR2) == -1)
		{
			write(2, "Error 2", 7);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(1, "Success\n", 8);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char	**argv)
{
	
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		str = argv[2];


		memset(&act, 0, sizeof(act));
		act.sa_flags = 0;
		act.sa_handler = send_data;
		sigemptyset(&act.sa_mask);
		sigaddset(&act.sa_mask, SIGUSR1);
		if (sigaction(SIGUSR1, &act, NULL) == -1)
		{
			write(1, "Error 1", 7);
			exit(EXIT_FAILURE);
		}

		first_send();
		while (1)
			pause();
	}
	exit(EXIT_SUCCESS);
}