/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_final_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:55 by glevin            #+#    #+#             */
/*   Updated: 2024/12/15 16:54:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sf_handle_waits(t_main *main, pid_t pid);

void	f_handle_final_cmd(t_main *main, t_pipex *pipex, t_tok *tok)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
		f_do_child(main, pipex, tok, 1);
	close(STDIN_FILENO);
	sf_handle_waits(main, pid);
}

void	sf_handle_waits(t_main *main, pid_t pid)
{
	int	wstatus;

	wstatus = 0;
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		main->exit_status = WEXITSTATUS(wstatus);
	if (WIFSIGNALED(wstatus))
		main->exit_status = WTERMSIG(wstatus) + 128;
	while (wait(NULL) != -1)
		;
	f_signal_setup(SIGMODE_INTERACTIVE);
}
