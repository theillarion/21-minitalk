/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:22 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 20:11:20 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#define LONG_MAX "9223372036854775807"
#define LONG_MIN "9223372036854775808"

static int	ft_isdigit(int symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return (1);
	return (0);
}

static int	ft_strncmp(const char	*str1, const char	*str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n && (str1[i] || str2[i]))
	{
		if ((t_uchar)str1[i] != (t_uchar)str2[i])
			return ((t_uchar)str1[i] - (t_uchar)str2[i]);
		i++;
	}
	return (0);
}

static int	ft_get_number(const char	*str, int sign)
{
	int		i;
	int		number;
	char	new_str[20];
	size_t	len;

	number = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	len = i;
	i = -1;
	while (i++ < 19 && len == 19 && str[i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	if (sign == 1
		&& (len > 19 || (len == 19 && ft_strncmp(new_str, LONG_MAX, len) >= 0)))
		return (-1);
	else if (sign == -1
		&& (len > 19 || (len == 19 && ft_strncmp(new_str, LONG_MIN, len) >= 0)))
		return (0);
	i = 0;
	while (ft_isdigit(str[i]))
		number = (number * 10) + (str[i++] - '0');
	return (number * sign);
}

int	ft_atoi(const char	*str)
{
	int	sign;

	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (ft_get_number(str, sign));
}
