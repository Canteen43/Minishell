/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:18:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/07 14:07:08 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_prep_next_command(t_pipex *pipex);
static void	sf_execute_child(t_main *main, t_pipex *pipex, t_tok *tok);
static void	handle_waits(t_main *main, pid_t pid);

void	f_do_pipe(t_main *main, t_pipex *pipex, t_tok *tok, int is_final)
{
	pid_t	pid;

	if (tok->redir_head)
		f_set_redirects(pipex, main, tok);
	if (pipe(pipex->fd) < 0)
		f_exit_clean(pipex, 1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		f_exit_clean(pipex, 1);
	}
	else if (pid == 0)
		sf_execute_child(main, pipex, tok);
	else
		sf_prep_next_command(pipex);
	if (is_final)
		handle_waits(main, pid);
}

static void	sf_prep_next_command(t_pipex *pipex)
{
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	pipex->infile = 0;
	pipex->outfile = 0;
}

static void	sf_execute_child(t_main *main, t_pipex *pipex, t_tok *tok)
{
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	f_do_execute(main, pipex, tok);
}

static void	handle_waits(t_main *main, pid_t pid)
{
	int wstatus;

	waitpid(pid, &wstatus, 1);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
	while (wait(NULL) != -1)
		;
}
