/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_token_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/16 09:39:21 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Takes a string and the starting index and returns index of the end of the
token. Returns -1 on failure.*/
int	f_get_token_end(char *str, int start)
{
	char	*ptr;
	int		end;

	if (str[start] == '>' || str[start] == '<' || str[start] == '|')
		return (start);
	if (str[start] == '\'' || str[start] == '\"')
	{
		ptr = f_strchr(str + start + 1, str[start]);
		if (ptr == NULL)
			return (-1);
		return (ptr - str);
	}
	end = start;
	while ((f_strchr(" \'\"<>|", str[end]) == NULL) && str[end] != '\0')
		end++;
	return (end - 1);
}
