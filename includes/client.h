/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:38 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:36:39 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char	*str);
int		ft_atoi(const char	*str);
void	ft_send_data(pid_t pid, char	*str);
int		main(int argc, char	**argv);

#endif