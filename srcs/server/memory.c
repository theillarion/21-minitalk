/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:26:17 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 20:27:29 by glashli          ###   ########.fr       */
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
