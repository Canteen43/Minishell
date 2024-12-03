/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:18:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/03 11:44:13 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		f_do_execute(main, pipex, tok);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
	}
}
