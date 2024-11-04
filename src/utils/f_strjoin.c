/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:09:31 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:09:46 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Joins two strings. Returns the new string. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_needed;
	char	*s3;

	size_needed = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = ft_calloc(size_needed, sizeof(char));
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
