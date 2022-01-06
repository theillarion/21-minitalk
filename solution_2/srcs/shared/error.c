/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:56 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 20:15:42 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_error(char	*err)
{
	write(2, "Error: ", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
