/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_delete_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:46:33 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:07:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_delete_pipes(t_main *main)
{
	t_tok	*tok;
	t_tok	*tmp;

	tok = main->tok_head;
	while (tok)
	{
		tmp = tok;
		tok = tok->next;
		if (tmp->type == PIPE)
			f_tok_remove_one_universal(&main->tok_head, tmp);
	}
}
