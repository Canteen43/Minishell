/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_keyvaluetostr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:04:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 14:01:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Converts a key and value to a string. Returns the string. */
char	*f_env_keyvaluetostr(t_env *node)
{
	char	*tmp;
	char	*str;

	tmp = f_strjoin(node->key, "=");
	if (tmp == NULL)
		return (NULL);
	if (node->value)
	{
		str = f_strjoin(tmp, node->value);
		free(tmp);
	}
	else
		str = tmp;
	if (str == NULL)
		return (NULL);
	return (str);
}