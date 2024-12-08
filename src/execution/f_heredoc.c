/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_heredoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:00:54 by glevin            #+#    #+#             */
/*   Updated: 2024/12/08 13:30:29 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_read_here_doc(t_pipex *pipex, int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (f_strlen(limiter) == 0)
		{
			if (f_strncmp(line, "\n", 1) == 0)
			{
				free(line);
				f_exit_clean(pipex, 0);
			}
		}
		else if (f_strncmp(line, limiter, f_strlen(limiter)) == 0)
		{
			free(line);
			f_exit_clean(pipex, 0);
		}
		write(fd[1], line, f_strlen(line));
		free(line);
	}
}

void	f_here_doc(t_pipex *pipex, char *limiter)
{
	pid_t	pid;
	int		wstatus;
	int		fd[2];

	if (pipe(fd) == 1)
	{
		perror("fork failed");
		f_exit_clean(pipex, 1);
	}
	pipex->heredoc_fd = fd[0];
	pid = fork();
	if (pid == 0)
		f_read_here_doc(pipex, fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &wstatus, 0);
	}
}
