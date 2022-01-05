/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:02 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:43:31 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
				kill(pid, SIGUSR1); // добавить обработчик ошибки
			else
				kill(pid, SIGUSR2); // тоже
			j /= 2;
		}
		i++;
	}
}
