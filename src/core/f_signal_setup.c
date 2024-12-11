/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_signal_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:01:04 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/11 12:08:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions:
static void	sf_handle_sigint_prompt(int signum);
static void	sf_handle_sigint_heredoc(int signum);
static void	sf_exit_signal_error(int code);
static void	sf_simple_sigaction(struct sigaction *sa_sig,
				void (*f_handler)(int), int signum);

/*Function to set up the handling of all our signals. Expects either
SIGSETSHELL or SIGSETCHILD as input an will set up accordingly.*/
void	f_signal_setup(int type)
{
	struct sigaction	sa_quit;
	struct sigaction	sa_int;

	if (type == SIGMODE_INTERACTIVE)
	{
		sf_simple_sigaction(&sa_quit, SIG_IGN, SIGQUIT);
		sf_simple_sigaction(&sa_int, sf_handle_sigint_prompt, SIGINT);
	}
	else if (type == SIGMODE_RESET)
	{
		sf_simple_sigaction(&sa_quit, SIG_DFL, SIGQUIT);
		sf_simple_sigaction(&sa_int, SIG_DFL, SIGINT);
	}
	else if (type == SIGMODE_WAITFORCHILD)
	{
		sf_simple_sigaction(&sa_quit, SIG_IGN, SIGQUIT);
		sf_simple_sigaction(&sa_int, SIG_IGN, SIGINT);
	}
	else if (type == SIGMODE_HEREDOC)
	{
		sf_simple_sigaction(&sa_quit, SIG_IGN, SIGQUIT);
		sf_simple_sigaction(&sa_int, sf_handle_sigint_heredoc, SIGINT);
	}
}

static void	sf_simple_sigaction(struct sigaction *sa_sig,
		void (*f_handler)(int), int signum)
{
	if (sigemptyset(&sa_sig->sa_mask) == -1)
		sf_exit_signal_error(1);
	sa_sig->sa_flags = 0;
	sa_sig->sa_handler = f_handler;
	if (sigaction(signum, sa_sig, NULL) == -1)
		sf_exit_signal_error(1);
}

static void	sf_exit_signal_error(int code)
{
	printf("Error setting up signal handling, exiting minishell...\n");
	exit(code);
}

static void	sf_handle_sigint_prompt(int signum)
{
	(void) signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	sf_handle_sigint_heredoc(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	exit(130);
}
