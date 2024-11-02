/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:01:04 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/02 19:39:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int signum);

void	f_handle_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sf_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		exit(1);
	sa.sa_flags = 0;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		exit(1);
	return ;
}

static void	handler(int signum)
{
	if (signum == SIGQUIT)
		return ;
	// handle SIGINT here
}
