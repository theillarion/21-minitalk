/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:19:34 by glashli           #+#    #+#             */
/*   Updated: 2022/01/07 17:00:23 by glashli          ###   ########.fr       */
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
	static size_t	i;

	(void)sig;
	(void)ucontext;
	if (g_buff && g_buff[i])
	{
		if (g_buff[i++] == '1')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_fail("data sending error");
		}	
		else if (kill(info->si_pid, SIGUSR2) == -1)
			ft_fail("data sending error");
	}
	else
		ft_success();
}
