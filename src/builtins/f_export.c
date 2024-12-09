/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:05:57 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_export(t_main *main, t_tok *tok)
{
	char	*key;
	char	*value;
	char	**args;

	args = tok->args + 1;
	if (!*args)
	{
		f_env(main);
		return ;
	}
	while (*args)
	{
		key = f_env_strtokey(main, *args);
		if (key == NULL)
		{
			printf("Invalid key.\n");
			return ;
		}
		value = f_env_strtovalue(main, *args);
		if (f_env_find_key(main->env_head, key))
			f_env_find_key(main->env_head, key)->value = value;
		else
			f_env_add_back(main, key, value);
		args++;
	}
}
