/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_expansions_for_toks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 10:40:14 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_do_expansions_for_toks(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->type != SQUOTE)
			f_do_expansions_in_str(main, &tok->str);
		tok = tok->next;
	}
}
