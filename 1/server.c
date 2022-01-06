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

	pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		write(1, "1", 1);
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		write(1, "0", 1);
		kill(info->si_pid, SIGUSR1);
	}
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