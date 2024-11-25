/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_create_lnklst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:49:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:53 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a linked list of env variables. Returns head. */
// TODO: Still need to figure out how to handle failure.
// (In Life but also in this function lol)
t_env	*f_env_create_lnklst(t_main *main, char **env)
{
	t_env	*head;
	int		i;
	char	*key;
	char	*value;

	head = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		key = f_env_strtokey(main, env[i]);
		value = f_env_strtovalue(main, env[i]);
		if (key == NULL || value == NULL)
		{
			f_env_del_list(head);
			return (NULL);
		}
		if (f_env_add_back(main, key, value) == -1)
		{
			f_env_del_list(head);
			return (NULL);
		}
		i++;
	}
	return (head);
}
