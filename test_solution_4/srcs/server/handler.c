/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:18 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 19:51:33 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern volatile sig_atomic_t	is_get_nesssage;
extern pid_t	pid;

void	ft_send_confirm(void)
{
	if (is_get_nesssage == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error("bit don't send");
		is_get_nesssage = 0;
	}
}

void	ft_get_bit(int sig, siginfo_t	*info, void	*ucontext)
{
	static unsigned char	letter;
	static size_t			i;

	if (pid != info->si_pid && info->si_pid != getpid())
		pid = info->si_pid;
	(void)ucontext;
	letter <<= 1;
	letter |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &letter, 1);
		letter = 0;
		i = 0;
	}
	is_get_nesssage = 1;
}
