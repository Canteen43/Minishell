/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_create_lnklst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:49:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 14:55:56 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a linked list of env variables. Returns head. */
void	f_env_create_lnklst(t_main *main, char **env)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (env[i] != NULL)
	{
		key = f_env_strtokey(main, env[i]);
		value = f_env_strtovalue(main, env[i]);
		if (key == NULL || value == NULL)
			f_free_and_exit(main, "Received unexpected env from main", 1);
		f_env_add_back(main, key, value);
		i++;
	}
}
