/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:05:13 by glevin            #+#    #+#             */
/*   Updated: 2024/11/21 14:37:33 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_do_execute(t_pipex *pipex, char *argv, char **envp)
{
	char	**cmd_args;
	char	*cmd;

	cmd_args = f_split(argv, ' ');
	cmd = f_get_cmd_path(pipex->paths, cmd_args[0]);
	if (!cmd)
	{
		perror("Command not found");
		f_free_split(cmd_args);
		f_exit_clean(pipex, 127);
	}
	if (execve(cmd, cmd_args, envp) == -1)
	{
		perror("execve failed");
		free(cmd);
		f_free_split(cmd_args);
		f_exit_clean(pipex, 127);
	}
}
