/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:02 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 18:28:56 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_error_send_data(void)
{
	ft_putendl_fd("\nError: data don't send.", 2);
	exit(EXIT_FAILURE);
}

void	ft_send_data(pid_t pid, char	*str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 0)
		exit(EXIT_FAILURE);
	while (str[i])
	{
		j = 128;
		while (j)
		{
			if (j & str[i])
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error_send_data();
			}		
			else if (kill(pid, SIGUSR2) == -1)
				ft_error_send_data();
			j /= 2;
		}
		i++;
	}
}
