/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:04:49 by glevin           ###   ########.fr       */
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
		printf("Too many arguments.\n");
		return ;
	}
	else
		path = args[1];
	if (chdir(path) == -1)
		printf("Changing directory unsuccessful.\n");
	f_env_find_key(main->env_head,
			"OLDPWD")->value = f_env_find_key(main->env_head, "PWD")->value;
	f_env_find_key(main->env_head, "PWD")->value = getcwd(NULL, 0);
	return ;
}
