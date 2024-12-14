/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_only_white_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:38:21 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/14 10:41:44 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	f_only_white_tokens(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->type != WHITE)
			return (false);
		tok = tok->next;
	}
	return (true);
}
