/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_delete_white_toks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:12:55 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/23 17:35:40 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Deletes all WHITE tokens from the token linked list. They were needed to
hold information on which tokens to join.*/
void	f_delete_white_toks(t_main *main)
{
	t_tok	*tok;

	main->tok_head = main->tok_head->next;
	tok = main->tok_head;
	while (tok)
	{
		if (tok->prev->type == WHITE)
			f_tok_del_one(tok->prev);
		tok = tok->next;
	}
}
