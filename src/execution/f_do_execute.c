/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:05:13 by glevin            #+#    #+#             */
/*   Updated: 2024/11/25 18:46:58 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	f_do_execute(t_pipex *pipex, char *argv, char **envp)
void	f_do_execute(t_main *main, t_pipex *pipex, t_tok *c_tok, char **envp)
{
	char	*cmd;
	
	cmd = f_get_cmd_path(main, pipex->paths, c_tok->str);
	if (!cmd)
	{
		perror("Command not found");
		f_exit_clean(pipex, 127);
	}
	if (execve(cmd, c_tok->args, envp) == -1)
	{
		perror("execve failed");
		free(cmd);
		f_exit_clean(pipex, 127);
	}
}
