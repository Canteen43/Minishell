/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:05:13 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 16:35:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_do_execute(t_main *main, t_pipex *pipex, t_tok *tok)
{
	char	*cmd;

	if (f_do_builtin(main, tok))
		exit(0);
	cmd = f_get_cmd_path(main, pipex->paths, tok->str);
	if (!cmd)
	{
		perror("Command not found");
		f_exit_clean(pipex, 127);
	}
	if (execve(cmd, tok->args, (char **)pipex->envp) == -1)
	{
		perror("execve failed");
		free(cmd);
		f_exit_clean(pipex, 127);
	}
}
