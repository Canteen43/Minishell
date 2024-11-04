/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_create_lnklst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:49:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 08:43:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a linked list of env variables. Returns head. */
// WIP: Still need to free on failure.
t_env	*f_env_create_lnklst(char **env)
{
	t_env	*head;
	int		i;
	char	*key;
	char	*value;

	head = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		key = f_env_key(env[i]);
		value = f_env_value(env[i]);
		if (key == NULL || value == NULL)
		{
			f_env_del_list(head);
			return (NULL);
		}
		if (f_env_add_back(&head, key, head) == -1)
		{
			f_env_del_list(head);
			return (NULL);
		}
		i++;
	}
	return (head);
}
