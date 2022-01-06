# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>

typedef struct sigaction t_sigaction;

pid_t pid;

void ft_handler(int sig, siginfo_t * info, void * ucontext)
{
	(void)ucontext;
	static unsigned char	letter;
	static size_t			i;

	pid = info->si_pid;
	letter <<= 1;
	if (sig == SIGUSR1)
		letter |= 1;
	//letter |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &letter, 1);
		letter = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	t_sigaction act;

	printf("PID: %d\n", getpid());
	memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);

	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
	{
		write(2, "Error 1", 7);
		exit(1);
	}
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}