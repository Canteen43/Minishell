/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:00:54 by glevin            #+#    #+#             */
/*   Updated: 2024/12/15 16:10:47 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static void	sf_read_heredoc(t_main *main, int *fd, char *limiter);

int	f_do_heredoc(t_main *main, t_tok *redir)
{
	pid_t	pid;
	int		wstatus;
	int		fd[2];

	if (pipe(fd) != 0)
		f_free_and_exit(main, PIPEFAIL, 1);
	pid = fork();
	if (pid == -1)
		f_free_and_exit(main, FORKFAIL, 1);
	if (pid == 0)
		sf_read_heredoc(main, fd, redir->args[0]);
	f_signal_setup(SIGMODE_WAITFORCHILD);
	close(fd[1]);
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
	if (main->exit_status != 0)
		return (1);
	redir->heredoc_fd = fd[0];
	f_signal_setup(SIGMODE_INTERACTIVE);
	return (0);
}

static void	sf_read_heredoc(t_main *main, int *fd, char *limiter)
{
	char	*line;

	f_signal_setup(SIGMODE_HEREDOC);
	close(fd[0]);
	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (!line)
		{
			printf("minishell: warning: here-document delimited by end-of-file"
				" (wanted `%s')\n",
				limiter);
			break ;
		}
		if (f_gc_add_node(main, line) == NULL)
			f_free_and_exit(main, MALLOCFAIL, 1);
		if (f_strcmp(line, limiter) == 0)
			break ;
		f_do_expansions_in_str(main, &line);
		write(fd[1], line, f_strlen(line));
		write(fd[1], "\n", 1);
	}
	close(fd[1]);
	f_gc_clean(main);
	exit(0);
}
