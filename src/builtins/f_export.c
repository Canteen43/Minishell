/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 09:30:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_export(t_main *main)
{
	char	*key;
	char	*value;
	char	**args;

	args = main->tok_head->args + 1;
	if (!*args)
	{
		f_env(main);
		return ;
	}
	while (*args)
	{
		key = f_env_strtokey(*args);
		if (key == NULL)
		{
			printf("Invalid key.\n");
			return ;
		}
		value = f_env_strtovalue(*args);
		if (f_env_find_key(main->env_head, key))
			f_env_find_key(main->env_head, key)->value = value;
		else
			f_env_add_back(&main->env_head, key, value);
		args++;
	}
}
