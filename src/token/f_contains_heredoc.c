/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_contains_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:31:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 18:34:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	f_contains_heredoc(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->type == REDIR_HEREDOC)
			return (true);
		tok = tok->next;
	}
	return (false);
}
