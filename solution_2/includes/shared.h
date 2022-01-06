/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:36 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 22:09:31 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef unsigned char		t_uchar;
typedef struct sigaction	t_sigaction;

void	*ft_memset(void	*str, int symbol, size_t len);
void	ft_error(char	*err);

#endif