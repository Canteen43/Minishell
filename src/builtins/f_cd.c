/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 09:42:58 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_cd(t_main *main)
{
	char **args;
	char* path;

	args = main->tok_head->args;
	if (args[1] == NULL)
		path = f_env_find_key(main->env_head, "HOME")->value;
	else if (args[2] != NULL)
	{
		printf("Too many arguments.\n");
		return ;
	}
	else
		path = args[1];
	if (chdir(path) == -1)
		printf("Changing directory unsuccessful.\n");
	f_env_find_key(main->env_head, "OLDPWD")->value
	 = f_env_find_key(main->env_head, "PWD")->value;
	f_env_find_key(main->env_head, "PWD")->value = getcwd(NULL, 0);
	return ;
}
