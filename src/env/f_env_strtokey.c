/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_strtokey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:58:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 13:54:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Extracts the key from string str (everything before the equal sign).
Allocates memory and returns pointer to key. Returns NULL on failure. */
char	*f_env_strtokey(char *str)
{
	int		len;
	char	*key;
	char	*eq_pos;

	if (str == NULL)
		return (NULL);
	eq_pos = f_strchr(str, '=');
	if (eq_pos == NULL)
		eq_pos = f_strchr(str, '\0');
	len = eq_pos - str;
	if (len == 0)
		return (NULL);
	key = (char *)malloc(sizeof(char) * (len + 1));
	if (key == NULL)
		return (NULL);
	f_memcpy(key, str, len);
	key[len] = '\0';
	return (key);
}
