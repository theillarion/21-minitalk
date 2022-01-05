/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:32 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 13:41:38 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char	*str);
void	ft_putchar_fd(char symbol, int fd);
void	ft_putendl_fd(char	*str, int fd);
void	ft_one();
void	ft_zero();
void	ft_print(char bit);
void	ft_initial_actions(struct sigaction *action_one,
			struct sigaction *action_zero);
void	ft_error_action(void);
int		main(void);

#endif