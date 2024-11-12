/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/12 18:24:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.
WIP: For now, it prints the tokens. Later it will create the linked list.*/
void	f_tokenize(char *str)
{
	char	*token;
	size_t	start;
	size_t	end;
	int		status;

	start = 0;
	while (str[start] != '\0')
	{
		end = start;
		status = DEFAULT;
		if (status == DEFAULT)
		{
			while (!f_strchr("\'\" \t", str[end]))
				end++;
		}
		
		else if (status == SQUOTE)
		{
			while (str[end] != '\'' && str[end] != '\0')
				end++;
		}
		else if (status == DQUOTE)
		{
			while (str[end] != '\"' && str[end] != '\0')
				end++;
		}
	}
	}
}
