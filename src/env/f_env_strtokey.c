/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_strtokey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:58:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 08:30:04 by kweihman         ###   ########.fr       */
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
		return (NULL);
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
