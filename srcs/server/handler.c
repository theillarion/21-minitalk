/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:49 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 15:00:20 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_print('1');
	else if (signum == SIGUSR2)
		ft_print('0');
}
