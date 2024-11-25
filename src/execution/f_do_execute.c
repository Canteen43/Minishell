/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:05:13 by glevin            #+#    #+#             */
/*   Updated: 2024/11/25 15:04:26 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	f_do_execute(t_pipex *pipex, char *argv, char **envp)
void	f_do_execute(t_pipex *pipex, t_tok *c_tok)
{
	char	*cmd;

	printf("c_tok->str: %s\n", c_tok->str);
	cmd = f_get_cmd_path(pipex->paths, c_tok->str);
	if (!cmd)
	{
		perror("Command not found");
		f_exit_clean(pipex, 127);
	}
	if (execve(cmd, c_tok->args, pipex->envp) == -1)
	{
		perror("execve failed");
		free(cmd);
		f_exit_clean(pipex, 127);
	}
}
