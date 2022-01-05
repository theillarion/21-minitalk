/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:55 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:45:09 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print(char bit)
{
	static unsigned char	letter;
	static size_t			i;

	letter <<= 1;
	letter |= bit - 48;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(letter, 1);
		i = 0;
		letter = 0;
	}
}
