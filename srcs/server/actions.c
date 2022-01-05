/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:45 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:46:17 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_initial_actions(struct sigaction *action_one,
			struct sigaction *action_zero)
{
	sigset_t	set;

	memset(&(*action_one), 0, sizeof(*action_one));
	memset(&(*action_zero), 0, sizeof(*action_zero));
	action_one->sa_handler = ft_one;
	action_zero->sa_handler = ft_zero;
	sigemptyset(&action_one->sa_mask);
	sigemptyset(&action_zero->sa_mask);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	action_one->sa_mask = set;
	action_zero->sa_mask = set;
}

void	ft_error_action(void)
{
	ft_putendl_fd("Error: invalid action.", 2);
	exit(EXIT_FAILURE);
}
