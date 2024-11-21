/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_expand_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/21 08:22:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_expand_variable(t_main *main)
{
	t_tok	*tok;
	char	*start;
	char	*end;
	char	*value;

	tok = main->tok_head;
	while (tok)
	{
		while (tok->type == SQUOTE)
			tok = tok->next;
		while (f_strchr(tok->str, '$'))
		{
			start = f_strchr(tok->str, '$') + 1;
			end = f_var_end(start);
			value = f_var_find_key(main, start, end);
			tok->str = f_var_new_string(main, tok->str, value, end);
		}
		tok = tok->next;
	}
}
