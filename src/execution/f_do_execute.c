/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:05:13 by glevin            #+#    #+#             */
/*   Updated: 2024/12/11 16:53:45 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sf_file_and_dir_checks(t_main *main, t_tok *tok);

void	f_do_execute(t_main *main, t_pipex *pipex, t_tok *tok)
{
	char	*cmd;

	if (tok->str == NULL)
		exit(0);
	if (f_do_builtin(main, tok))
		exit(0);
	sf_file_and_dir_checks(main, tok);
	cmd = f_get_cmd_path(main, pipex->paths, tok->str);
	if (!cmd)
	{
		write(STDERR_FILENO, CMDFAIL, f_strlen(CMDFAIL));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	if (execve(cmd, tok->args, (char **)pipex->envp) == -1)
	{
		perror("execve failed");
		f_exit_clean(pipex, 127);
	}
}

static void	sf_file_and_dir_checks(t_main *main, t_tok *tok)
{
	struct stat	path_stat;

	if ((strncmp(tok->str, "/", 1) == 0 || strncmp(tok->str, "./", 2) == 0
			|| strncmp(tok->str, "../", 3) == 0 || tok->str[0] == '/'))
	{
		if (stat(tok->str, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
			f_free_and_exit(main, DIRFAIL, 126);
		if (access(tok->str, F_OK) != 0)
			f_free_and_exit(main, MISSINGFILEFAIL, 127);
		if (stat(tok->str, &path_stat) != 0 || !S_ISREG(path_stat.st_mode)
			|| access(tok->str, X_OK) != 0)
			f_free_and_exit(main, PERMDENIED, 126);
	}
}
