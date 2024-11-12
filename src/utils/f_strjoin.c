/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:09:31 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 14:19:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Joins two strings. Returns the new string. Expects valid strings.*/
char	*f_strjoin(char const *s1, char const *s2)
{
	size_t	size_needed;
	char	*s3;

	size_needed = f_strlen(s1) + f_strlen(s2) + 1;
	s3 = malloc(size_needed * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	s3 -= (size_needed - 1);
	return (s3);
}
