/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_expand_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 19:18:59 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_expand_variable(t_main *main)
{
	t_tok	*tok;
	char	*start;
	char	*end;
	char	*var_string;

	tok = main->tok_head;
	while (tok)
	{
		while (f_strchr(tok->str, '$'))
		{
			start = f_strchr(tok->str, '$') + 1;
			end = f_var_end(start);
			var_string = malloc(end - start + 2);
			if (!var_string)
				ERROR;
			f_strncpy(var_string, start, end - start + 1);
			var_string[end-start + 1] = '\0';
			
		}
		tok = tok->next;
	}
}
