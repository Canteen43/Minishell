/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_check_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:55:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/16 12:04:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static bool	f_op_space_op(t_tok *tok);
static bool	f_illegal_2_op(t_tok *tok);
static bool	f_3_ops(t_tok *tok);

/*Checks if the syntax of the tokens is correct. Returns the token where the
syntax is incorrect. Returns NULL for correct syntax.*/
t_tok	*f_tok_check_syntax(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (f_strscmp(tok->str, 3, ">", "<", "|"))
		{
			if (f_op_space_op(tok))
				return (tok->next->next);
			if (f_illegal_2_op(tok))
				return (tok->next);
			if (f_3_ops(tok))
				return (tok->next->next);
		}
		tok = tok->next;
	}
	return (NULL);
}

static bool	f_op_space_op(t_tok *tok)
{
	if (tok->next->str != NULL
		&& f_strcmp(tok->next->str, " ") == 0
		&& tok->next->next->str != NULL
		&& f_strscmp(tok->next->next->str, 3, ">", "<", "|"))
		return (true);
	return (false);
}

static bool	f_illegal_2_op(t_tok *tok)
{
	if ((tok->next->str != NULL
			&& f_strscmp(tok->next->str, 3, ">", "<", "|"))
		&& (f_strcmp(tok->next->str, "|") == 0
			|| f_strcmp(tok->next->str, tok->str) != 0))
		return (true);
	return (false);
}

static bool	f_3_ops(t_tok *tok)
{
	if (tok->next->str != NULL
		&& f_strscmp(tok->next->str, 3, ">", "<", "|")
		&& tok->next->next->str != NULL
		&& f_strscmp(tok->next->next->str, 3, ">", "<", "|"))
		return (true);
	return (false);
}
