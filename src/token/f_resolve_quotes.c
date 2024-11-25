/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_resolve_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:39:45 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/23 17:04:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: handle malloc failure
void	f_resolve_quotes(t_main *main)
{
	t_tok	*tok;
	size_t	newlen;
	char	*newstr;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->type == DQUOTE || tok->type == SQUOTE)
		{
			newlen = f_strlen(tok->str) - 2;
			newstr = malloc(newlen + 1);
			strncpy(newstr, tok->str + 1, newlen);
			newstr[newlen] = '\0';
			tok->str = newstr;
			tok->type = WORD;
		}
		tok = tok->next;
	}
}
