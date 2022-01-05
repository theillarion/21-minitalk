/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:37:06 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:48:56 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	action_one;
	struct sigaction	action_zero;

	printf("PID: %d\n", getpid());
	ft_initial_actions(&action_one, &action_zero);
	if (sigaction(SIGUSR1, &action_one, NULL) == -1
		|| sigaction(SIGUSR2, &action_zero, NULL) == -1)
		ft_error_action();
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
