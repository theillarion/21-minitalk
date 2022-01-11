/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:17:33 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 19:50:48 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_buff;

void	ft_fill_array(char	*arg)
{
	int	i;
	int	j;

	i = 0;
	g_buff = (char *)ft_calloc(ft_strlen(arg) * 8 + 1, sizeof(char));
	if (g_buff == NULL)
		ft_error("Memory cannot be allocated");
	while (*arg)
	{
		j = 128;
		while (j)
		{
			if (j & *arg)
				g_buff[i] = '1';
			else
				g_buff[i] = '0';
			j /= 2;
			i++;
		}
		arg++;
	}
}

void	ft_initial_sigaction(struct sigaction *action)
{
	ft_memset(&(*action), 0, sizeof(*action));
	action->sa_flags = SA_SIGINFO;
	action->sa_sigaction = ft_send_bit;
	sigemptyset(&action->sa_mask);
	sigaddset(&action->sa_mask, SIGUSR1);
}

void	ft_initial_siginfo(siginfo_t	*info, char	*s_pid)
{
	ft_memset(&(*info), 0, sizeof(*info));
	info->si_pid = ft_atoi(s_pid);
	if (info->si_pid < 1)
		ft_error("invalid PID");
}
