/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/13 13:55:21 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*f_strdup(const char *s)
{
	char	*ptr;
	char	*start;

	ptr = malloc((f_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (start);
}
