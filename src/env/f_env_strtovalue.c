/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_strtovalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 15:04:47 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Extracts the value from string str (everything after the equal sign).
Allocates memory and returns pointer to value. Returns NULL on failure. */
char	*f_env_strtovalue(char *str)
{
	int		len;
	char	*value;
	char	*eq_pos;

	if (str == NULL)
		return (NULL);
	eq_pos = f_strchr(str, '=');
	if (eq_pos == NULL)
		return (NULL);
	len = f_strlen(eq_pos + 1);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (value == NULL)
		return (NULL);
	f_memcpy(value, eq_pos + 1, len);
	value[len] = '\0';
	return (value);
}
