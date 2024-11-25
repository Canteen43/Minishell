/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_join_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:58:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:32:45 by kweihman         ###   ########.fr       */
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
		while (tok->type == WORD && tok->next && tok->next->type == WORD)
		{
			tok->str = f_strjoin(main, tok->str, tok->next->str);
			f_tok_remove_one(tok->next);
		}
		tok = tok->next;
	}
}
