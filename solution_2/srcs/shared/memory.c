/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:27 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 21:28:22 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*ft_memset(void	*str, int symbol, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((t_uchar *)str)[i] = (t_uchar)symbol;
		i++;
	}
	return (str);
}

static void	ft_bzero(void	*str, size_t n)
{
	ft_memset(str, '\0', n);
}

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*array;

	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}
