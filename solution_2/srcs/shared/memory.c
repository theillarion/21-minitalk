/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:27 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 14:32:28 by glashli          ###   ########.fr       */
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
