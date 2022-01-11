/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:17 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 18:57:11 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char	**argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 1)
		{
			ft_putendl_fd("\nError: incorrect PID", 2);
			exit(EXIT_FAILURE);
		}		
		ft_send_data(pid, argv[2]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putendl_fd("\nError: wrong number of arguments", 2);
		exit(EXIT_FAILURE);
	}
}