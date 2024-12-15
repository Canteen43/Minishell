/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:18:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/15 12:00:29 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_handle_cmd(t_main *main, t_pipex *pipex, t_tok *tok)
{
	pid_t	pid;

	if (pipe(pipex->fd) < 0)
		exit(1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
		f_do_child(main, pipex, tok, 0);
	else
	{
		close(pipex->fd[WRITE]);
		dup2(pipex->fd[READ], STDIN_FILENO);
		close(pipex->fd[READ]);
	}
}
