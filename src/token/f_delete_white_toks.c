/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_delete_white_toks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:12:55 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/24 13:00:33 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Deletes all WHITE tokens from the token linked list. They were needed to
hold information on which tokens to join.*/
void	f_delete_white_toks(t_main *main)
{
	t_tok	*tok;

	while (main->tok_head->type == WHITE)
		main->tok_head = main->tok_head->next;
	main->tok_head->prev = NULL;
	tok = main->tok_head;
	while (tok)
	{
		if (tok->type == WHITE)
			f_tok_remove_one(tok);
		tok = tok->next;
	}
}
