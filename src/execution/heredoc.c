/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:00:54 by glevin            #+#    #+#             */
/*   Updated: 2024/11/17 13:21:10 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_here_doc(t_pipex *pipex, int *fd, char *limiter)
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
				exit_clean(pipex, 0);
			}
		}
		else if (f_strncmp(line, limiter, f_strlen(limiter)) == 0)
		{
			free(line);
			exit_clean(pipex, 0);
		}
		write(fd[1], line, f_strlen(line));
		free(line);
	}
}

void	here_doc(t_pipex *pipex, char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		exit_clean(pipex, 1);
	if (pipe(fd) == 1)
	{
		perror("fork failed");
		exit_clean(pipex, 1);
	}
	pid = fork();
	if (pid == 0)
		read_here_doc(pipex, fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
