/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:10 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 14:32:14 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_initial_action(struct sigaction *action)
{
	ft_memset(&(*action), 0, sizeof(*action));
	action->sa_flags = SA_SIGINFO;
	action->sa_sigaction = ft_get_bit;
	sigemptyset(&action->sa_mask);
	sigaddset(&action->sa_mask, SIGUSR1);
	sigaddset(&action->sa_mask, SIGUSR2);
}
