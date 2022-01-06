/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:19:34 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 20:20:22 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern char	*g_buff;

static void	ft_success(void)
{
	ft_putendl_fd("Data sent successfully", 1);
	exit(EXIT_SUCCESS);
}

void	ft_send_bit(int sig, siginfo_t	*info, void	*ucontext)
{
	(void)sig;
	(void)ucontext;
	if (g_buff && *g_buff)
	{
		if (*(g_buff++) == '1')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_error("data sending error");
		}	
		else if (kill(info->si_pid, SIGUSR2) == -1)
			ft_error("data sending error");
	}
	else
		ft_success();
}
