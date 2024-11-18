/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/11/17 13:30:28 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_pipe(t_pipex *pipex, char **envp, char *argv)
{
	int		status;
	pid_t	pid;
	int		fd[2];

	status = 0;
	if (pipe(fd) < 0)
		exit_clean(pipex, 1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit_clean(pipex, 1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(pipex, argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	init_pipex(t_pipex *pipex, char **envp)
{
	char	*paths;

	while (f_strncmp("PATH", *envp, 4))
		envp++;
	paths = *envp + 5;
	pipex->paths = f_split(paths, ':');
}

void	final_execute(t_pipex pipex, int argc, char **argv, char **envp)
{
	int	status;

	dup2(pipex.outfile, STDOUT_FILENO);
	execute(&pipex, argv[argc - 2], envp);
	while (wait(&status) > 0)
		exit_clean(&pipex, 0);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		return (1);
	init_pipex(&pipex, envp);
	if (f_strncmp(argv[1], "here_doc", 8) == 0)
	{
		pipex.outfile = open_file(&pipex, argv[argc - 1], 0);
		here_doc(&pipex, argv[2], argc);
		i = 3;
	}
	else
	{
		pipex.infile = open_file(&pipex, argv[1], 1);
		pipex.outfile = open_file(&pipex, argv[argc - 1], 2);
		dup2(pipex.infile, 0);
		i = 2;
	}
	while (i < argc - 2)
		do_pipe(&pipex, envp, argv[i++]);
	final_execute(pipex, argc, argv, envp);
	return (0);
}
