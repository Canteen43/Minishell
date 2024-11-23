/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_join_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:58:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/23 17:08:31 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Joins adjacent WORD tokens into one token. Used after variable expansion and
quote resolution to join strings that were not separate by whitespace but were
in quotes.*/
void	f_join_tokens(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->next && tok->type == WORD && tok->next->type == WORD)
		{
			tok->str = f_strjoin(tok->str, tok->next->str);
			f_tok_del_one(tok->next);
		}
		tok = tok->next;
	}
}
