/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_check_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:55:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/08 15:30:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static bool	sf_op_after_redir(t_tok *tok);
static bool	sf_pipe_after_pipe(t_tok *tok);
static bool	sf_nothing_after_op(t_tok *tok);
static int	sf_write_error_and_return(char *unex_tok);

/*Checks if the syntax of the tokens is correct. Returns the token where the
syntax is incorrect. Returns NULL for correct syntax.*/
int	f_tok_check_syntax(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	while (tok)
	{
		if (sf_op_after_redir(tok))
			return (sf_write_error_and_return(tok->str));
		if (sf_pipe_after_pipe(tok))
			return (sf_write_error_and_return(tok->str));
		if (sf_nothing_after_op(tok))
			return (sf_write_error_and_return("newline"));
		tok = tok->next;
	}
	return (0);
}

static bool	sf_op_after_redir(t_tok *tok)
{
	if (f_is_operator(tok)
		&& (f_tok_is_redir(tok->prev)
			|| (tok->prev && tok->prev->type == WHITE
				&& f_tok_is_redir(tok->prev->prev))))
		return (true);
	return (false);
}

static bool	sf_pipe_after_pipe(t_tok *tok)
{
	if (tok->type == PIPE
		&& ((tok->prev && tok->prev->type == PIPE)
			|| (tok->prev && tok->prev->type == WHITE
				&& tok->prev->prev && tok->prev->prev->type == WHITE)))
		return (true);
	return (false);
}

static bool	sf_nothing_after_op(t_tok *tok)
{
	if (f_is_operator(tok)
		&& (tok->next == NULL
			|| (tok->next->type == WHITE
				&& tok->next->next == NULL)))
		return (true);
	return (false);
}

static int	sf_write_error_and_return(char *unex_tok)
{
	printf("Syntax error near unexpected token `%s'\n", unex_tok);
	return (1);
}
