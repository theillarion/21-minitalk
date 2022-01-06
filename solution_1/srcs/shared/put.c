/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:58 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 23:17:39 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

void	ft_putstr_fd(char	*str, int fd)
{
	if (str != NULL)
		write(fd, str, ft_strlen(str));
}

void	ft_putchar_fd(char symbol, int fd)
{
	write(fd, &symbol, 1);
}

void	ft_putendl_fd(char	*str, int fd)
{
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}
