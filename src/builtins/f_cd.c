/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/14 13:58:55 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_file_dir_error(t_main *main, char *path);

void	f_cd(t_main *main, t_tok *tok)
{
	char	**args;
	char	*path;
	t_env	*pwd;

	args = tok->args;
	if (args[1] == NULL)
		path = f_env_find_key(main->env_head, "HOME")->value;
	else if (args[2] != NULL)
	{
		write(STDERR_FILENO, "minishell: cd: too many arguments\n", 34);
		main->exit_status = 1;
		return ;
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		write_file_dir_error(main, path);
		return ;
	}
	pwd = f_env_find_key(main->env_head, "PWD");
	f_env_find_key(main->env_head, "OLDPWD")->value = pwd->value;
	pwd->value = getcwd(NULL, 0);
	main->exit_status = 0;
	return ;
}

static void	write_file_dir_error(t_main *main, char *path)
{
	write(STDERR_FILENO, "minishell: cd: ", 15);
	write(STDERR_FILENO, path, f_strlen(path));
	write(STDERR_FILENO, ": No such file or directory\n", 28);
	main->exit_status = 1;
}
