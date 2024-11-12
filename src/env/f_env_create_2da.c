/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_create_2da.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:43:38 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:52:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a 2d array of env variables. Returns the 2d array. */
char	**f_env_create_2da(t_env *head)
{
	char	**env;
	int		i;

	env = (char **)malloc(sizeof(char *) * (f_env_lstlen(head) + 1));
	if (env == NULL)
		return (NULL);
	i = 0;
	while (head != NULL)
	{
		env[i] = f_env_keyvaluetostr(head);
		if (env[i] == NULL)
		{
			f_env_del_2da(env);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}