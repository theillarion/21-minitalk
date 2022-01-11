/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:19:34 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 20:07:12 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern char	*g_buff;
extern pid_t pid;
volatile sig_atomic_t	is_send_bit;

static void	ft_success(void)
{
	write(1, "Data sent successfully\n", 23);
	if (g_buff != NULL)
		free(g_buff);
	exit(EXIT_SUCCESS);
}

void	ft_send(void)
{
	if (is_send_bit == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_fail("gggg");
	}
	else if (is_send_bit == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_fail("gggg");
	}
}

void	ft_send_bit(int sig, siginfo_t	*info, void	*ucontext)
{
	static size_t	i;

	if (pid != info->si_pid && info->si_pid != getpid())
		pid = info->si_pid;
	(void)sig;
	(void)ucontext;
	if (g_buff && g_buff[i])
	{
		if (g_buff[i++] == '1')
		{
			is_send_bit = 1;
		}
		else
			is_send_bit = 0;
	}
	else
		ft_success();
}
