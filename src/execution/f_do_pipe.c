/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:18:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/07 17:07:46 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_execute_child(t_main *main, t_pipex *pipex, t_tok *tok);
static void	sf_prep_next_command(t_pipex *pipex);

void	f_do_pipe(t_main *main, t_pipex *pipex, t_tok *tok)
{
	pid_t	pid;

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
}

static void	sf_execute_child(t_main *main, t_pipex *pipex, t_tok *tok)
{
	if (tok->redir_head)
		f_set_redirects(pipex, main, tok);
	if (pipex->infile != -1)
	{
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	if (pipex->outfile != -1)
	{
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	else
	{
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
	}
	close(pipex->fd[0]);
	f_do_execute(main, pipex, tok);
}

static void	sf_prep_next_command(t_pipex *pipex)
{
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
}
