/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:18 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 20:15:27 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_get_bit(int sig, siginfo_t	*info, void	*ucontext)
{
	static unsigned char	letter;
	static size_t			i;

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
	kill(info->si_pid, SIGUSR1);
}
