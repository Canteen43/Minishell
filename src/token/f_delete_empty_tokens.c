/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_delete_empty_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:21:11 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/14 10:29:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Deletes empty tokens from the list. Those can occur if environment variables
expand to nothing. E.g. tok->str = "$EMPTY".*/
void	f_delete_empty_tokens(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (f_strcmp(tok->str, "") == 0)
			f_tok_remove_one(tok);
		tok = tok->next;
	}
}
