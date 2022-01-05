/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:36:32 by glashli           #+#    #+#             */
/*   Updated: 2022/01/05 23:21:36 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>
# include "shared.h"

void	*ft_memset(void	*str, int symbol, size_t len);
void	ft_putnbr_fd(int number, int fd);
void	ft_putstr_fd(char	*str, int fd);
void	ft_putchar_fd(char symbol, int fd);
void	ft_handler(int signum);
void	ft_print(char bit);
void	ft_initial_action(struct sigaction *action_one);
void	ft_error_action(void);
int		main(void);

#endif