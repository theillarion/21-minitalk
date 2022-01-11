/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:32 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 19:53:16 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

volatile sig_atomic_t	is_get_nesssage;
pid_t	pid;

int	main(void)
{
	t_sigaction	action;

	pid = -1;
	is_get_nesssage = 0;
	is_get_nesssage = 0;
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	ft_initial_action(&action);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error("invalid action");
	while (1)
	{
		pause();
		ft_send_confirm();
	}
	exit(EXIT_SUCCESS);
}
