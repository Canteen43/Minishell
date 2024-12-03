/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_final_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:55 by glevin            #+#    #+#             */
/*   Updated: 2024/12/03 12:44:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_final_execute(t_main *main, t_pipex *pipex, t_tok *tok)
{
	int		wstatus;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		f_exit_clean(pipex, 1);
	}
	else if (pid == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->outfile, STDOUT_FILENO);
		f_do_execute(main, pipex, tok);
	}
	waitpid(pid, &wstatus, 1);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
	while (wait(NULL) != -1)
		;
}
