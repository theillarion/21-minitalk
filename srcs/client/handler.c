/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:19:34 by glashli           #+#    #+#             */
/*   Updated: 2022/01/29 15:39:56 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern char	*g_buff;

static void	ft_success(void)
{
	write(1, "Data sent successfully\n", 23);
	if (g_buff != NULL)
		free(g_buff);
	exit(EXIT_SUCCESS);
}

void	ft_send_bit(int sig, siginfo_t	*info, void	*ucontext)
{
	static pid_t	pid;
	static size_t	i;

	if (info->si_pid != 0)
		pid = info->si_pid;
	(void)sig;
	(void)ucontext;
	if (g_buff && g_buff[i])
	{
		if (g_buff[i++] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_fail("data sending error");
		}	
		else if (kill(pid, SIGUSR2) == -1)
			ft_fail("data sending error");
	}
	else
		ft_success();
}
