/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_expandable_dollar_sign.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:41:34 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns pointer to first dollar sign that is follow by a zero or a possible
env variable*/
char	*f_expandable_dollar_sign(char *str)
{
	char	*ptr;
	char	*next;

	ptr = f_strchr(str, '$');
	if (ptr == NULL)
		return (NULL);
	next = ptr + 1;
	if (*next != '?' && *next != '_' && !f_is_alpha(*next))
		return (NULL);
	return (ptr);
}
