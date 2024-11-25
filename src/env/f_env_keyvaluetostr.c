/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_keyvaluetostr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:04:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:59:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Converts a key and value to a string. Returns the string. */
char	*f_env_keyvaluetostr(t_main *main, t_env *node)
{
	char	*tmp;
	char	*str;

	tmp = f_strjoin(main, node->key, "=");
	if (node->value)
		str = f_strjoin(main, tmp, node->value);
	else
		str = tmp;
	return (str);
}
