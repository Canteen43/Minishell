/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_single_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:09:46 by glevin            #+#    #+#             */
/*   Updated: 2024/12/14 14:31:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_final_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:55 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 15:55:58 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_handle_wait(t_main *main, pid_t pid);
static void	sf_handle_buildtin(t_main *main, t_pipex *pipex, t_tok *tok);

void	f_handle_single_cmd(t_main *main, t_pipex *pipex, t_tok *tok)
{
	pid_t	pid;

	if (f_is_builtin(tok))
	{
		sf_handle_buildtin(main, pipex, tok);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
		f_do_child(main, pipex, tok, 1);
	sf_handle_wait(main, pid);
}

static void	sf_handle_buildtin(t_main *main, t_pipex *pipex, t_tok *tok)
{
	f_set_redirects(pipex, tok);
	if (pipex->infile == -2 || pipex->outfile == -2)
	{
		main->exit_status = 1;
		return ;
	}
	else
	{
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
		f_do_builtin(main, tok);
	}
}

static void	sf_handle_wait(t_main *main, pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
}
