/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:37:39 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 19:50:44 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern char	*g_buff;

void	ft_fail(char	*err)
{
	write(2, "Error: ", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	if (g_buff != NULL)
		free(g_buff);
	exit(EXIT_FAILURE);
}
