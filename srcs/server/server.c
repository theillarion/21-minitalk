/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:37:06 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 15:06:28 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	action;

	printf("PID: %d\n", getpid());
	ft_initial_action(&action);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error_action();
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
