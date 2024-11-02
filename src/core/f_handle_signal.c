/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:01:04 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/02 19:59:38 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_handler(int signum);

void	f_handle_signals(void)
{
	struct sigaction	sa_sigquit;
	struct sigaction	sa_sigint;

	if (sigemptyset(&sa_sigquit.sa_mask) == -1)
		exit(1);
	if (sigemptyset(&sa_sigint.sa_mask) == -1)
		exit(1);
	sa_sigquit.sa_flags = 0;
	sa_sigint.sa_flags = 0;
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigint.sa_handler = sf_handler;
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		exit(1);
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		exit(1);
	return ;
}

static void	sf_handler(int signum)
{
	(void)signum;
	// handle SIGINT here
}
