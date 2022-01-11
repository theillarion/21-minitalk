/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:43 by glashli           #+#    #+#             */
/*   Updated: 2022/01/11 19:47:01 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "shared.h"

void	ft_putnbr_fd(int number, int fd);
void	ft_get_bit(int sig, siginfo_t *info, void *ucontext);
void	ft_initial_action(struct sigaction *action_one);
void	ft_send_confirm(void);
int		main(void);

#endif