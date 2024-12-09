/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_final_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:55 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 14:48:54 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_handle_waits(t_main *main, pid_t pid);
static void	sf_execute_child(t_main *main, t_pipex *pipex, t_tok *tok);

void	f_handle_final_command(t_main *main, t_pipex *pipex, t_tok *tok)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		f_exit_clean(pipex, 1);
	}
	else if (pid == 0)
		sf_execute_child(main, pipex, tok);
	sf_handle_waits(main, pid);
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
		dup2(main->stdout_copy, STDOUT_FILENO);
	close(pipex->fd[0]);
	f_do_execute(main, pipex, tok);
}

static void	sf_handle_waits(t_main *main, pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
	while (wait(NULL) != -1)
		;
}
