/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/10 11:50:29 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_cd(t_main *main, t_tok *tok)
{
	char	**args;
	char	*path;

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
		write(STDERR_FILENO, "minishell: cd: ", 15);
		write(STDERR_FILENO, path, f_strlen(path));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		main->exit_status = 1;
		return ;
	}
	f_env_find_key(main->env_head,
			"OLDPWD")->value = f_env_find_key(main->env_head, "PWD")->value;
	f_env_find_key(main->env_head, "PWD")->value = getcwd(NULL, 0);
	main->exit_status = 0;
	return ;
}
