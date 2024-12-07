/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_expand_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/07 11:07:35 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static char	*sf_coupled_dollar_sign(char *str);

void	f_expand_variables(t_main *main)
{
	t_tok	*tok;
	char	*start;
	char	*end;
	char	*value;

	tok = main->tok_head;
	while (tok)
	{
		while (tok->type != SQUOTE && sf_coupled_dollar_sign(tok->str))
		{
			start = sf_coupled_dollar_sign(tok->str) + 1;
			end = f_var_end(start);
			value = f_var_find_key(main, start, end);
			tok->str = f_var_new_string(main, tok->str, value, end);
		}
		tok = tok->next;
	}
}

static char	*sf_coupled_dollar_sign(char *str)
{
	char	*ptr;
	char	*next;

	ptr = f_strchr(str, '$');
	if (ptr == NULL)
		return (NULL);
	next = ptr + 1;
	if (*next == ' ' || *next == '\0' || *next == '"')
		return (NULL);
	return (ptr);
}
