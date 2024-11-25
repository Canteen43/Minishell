/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:37:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*f_strdup(t_main *main, const char *s)
{
	char	*ptr;
	char	*start;

	ptr = f_gc_malloc(main, (f_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		f_free_and_exit(main, MALLOCFAIL, 1);
	start = ptr;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (start);
}
