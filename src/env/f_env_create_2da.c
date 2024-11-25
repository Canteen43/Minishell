/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_create_2da.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:43:38 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a 2d array of env variables. Returns the 2d array. */
char	**f_env_create_2da(t_main *main)
{
	char	**env;
	t_env	*node;
	int		i;

	env = (char **)f_gc_malloc(main,
			sizeof(char *) * (f_env_lstlen(main->env_head) + 1));
	if (!env)
		f_free_and_exit(main, MALLOCFAIL, 1);
	i = 0;
	node = main->env_head;
	while (node != NULL)
	{
		env[i] = f_env_keyvaluetostr(main, node);
		if (env[i] == NULL)
		{
			f_env_del_2da(env);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
