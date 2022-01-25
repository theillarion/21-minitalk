/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:36:02 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 22:15:23 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static void	ft_putchar_fd(char symbol, int fd)
{
	write(fd, &symbol, 1);
}

void	ft_putnbr_fd(int number, int fd)
{
	if (number == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (number < 0)
		{
			ft_putchar_fd('-', fd);
			number *= -1;
		}
		if (number > 9)
		{
			ft_putnbr_fd(number / 10, fd);
			ft_putnbr_fd(number % 10, fd);
		}
		else
			ft_putchar_fd(number + 48, fd);
	}
}
