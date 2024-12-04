/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_toks_to_cmds_n_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:11:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 13:40:55 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static Function:
static void	sf_handle_word(t_main *main, t_tok *tok, bool *cmd_set);

/*Iterates through linked list of tokens. Inbetween pipes, it will make the
first word a command and the rest its args.*/
void	f_toks_to_cmds_n_args(t_main *main)
{
	t_tok	*tok;
	bool	cmd_set;

	tok = main->tok_head;
	cmd_set = false;
	while (tok)
	{
		if (tok->type == PIPE)
			cmd_set = false;
		else if (tok->type == WORD)
			sf_handle_word(main, tok, &cmd_set);
		tok = tok->next;
	}
}

static void	sf_handle_word(t_main *main, t_tok *tok, bool *cmd_set)
{
	t_tok	*target;

	target = NULL;
	if (tok->prev && f_tok_is_redir(tok->prev) && tok->prev->args == NULL)
		target = tok->prev;
	else if (*cmd_set == false)
	{
		tok->type = COMMAND;
		f_add_arg_to_tok(main, tok->str, tok);
		*cmd_set = true;
	}
	else if (*cmd_set == true)
	{
		target = tok->prev;
		while (target->type != COMMAND)
			target = target->prev;
	}
	if (target)
	{
		f_add_arg_to_tok(main, tok->str, target);
		f_tok_remove_one(tok);
	}
}
