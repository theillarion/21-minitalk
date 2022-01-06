/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:45 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 14:57:01 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_initial_action(struct sigaction *action_one)
{
	memset(&(*action_one), 0, sizeof(*action_one));
	action_one->sa_handler = ft_handler;
	sigemptyset(&action_one->sa_mask);
	sigaddset(&action_one->sa_mask, SIGUSR1);
	sigaddset(&action_one->sa_mask, SIGUSR2);
}

void	ft_error_action(void)
{
	ft_putendl_fd("Error: invalid action.", 2);
	exit(EXIT_FAILURE);
}
