/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:16:06 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 20:17:39 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char	**argv)
{
	t_sigaction	action;
	siginfo_t	info;

	if (argc == 3)
	{
		ft_initial_sigaction(&action);
		ft_initial_siginfo(&info, argv[1]);
		ft_fill_array(argv[2]);
		if (sigaction(SIGUSR1, &action, NULL) == -1)
			ft_error("invalid_action");
		ft_send_bit(0, &info, NULL);
		while (1)
			pause();
		exit(EXIT_SUCCESS);
	}
	else
		ft_error("wrong number of arguments");
}
