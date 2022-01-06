/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glashli <glashli@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:32:51 by glashli           #+#    #+#             */
/*   Updated: 2022/01/06 21:46:57 by glashli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "shared.h"

void	ft_initial_sigaction(struct sigaction *action);
void	ft_initial_siginfo(siginfo_t	*info, char	*s_pid);
int		ft_atoi(const char	*str);
void	ft_fill_array(char	*arg);
void	ft_fail(char	*err);
void	ft_send_bit(int sig, siginfo_t *info, void *ucontext);
int		main(int argc, char	**argv);

#endif