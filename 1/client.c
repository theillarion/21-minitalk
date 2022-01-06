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

void success()
{
	write(1, "Success\n", 8);
	exit(EXIT_SUCCESS);
}

char	*ggg(char	*arg)
{
	char	*str;
	int		i;
	int 	j;

	i = 0;
	str = (char*)malloc(sizeof(char) * (strlen(arg) * 8 + 1));
	if (str == NULL)
		exit(EXIT_SUCCESS);
	str[strlen(str)] = '\0';
	while (*arg)
	{
		j = 128;
		while (j)
		{
			if (j & *arg)
				str[i] = '1';	
			else
				str[i] = '0';
			j /= 2;
			i++;
		}
		arg++;
	}
	return (str);
}

int main(int argc, char	**argv)
{
	
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		str = ggg(argv[2]);
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

		send_data();
		while (1)
			pause();
	}
	exit(EXIT_SUCCESS);
}