/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_create_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:11:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/24 15:32:40 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Iterates through linked list of tokens. Inbetween pipes, it will make the
first word a command and the rest its args.*/
void	f_toks_to_cmds_n_args(t_main *main)
{
	t_tok	*tok;
	t_tok	*target;
	bool	cmd_set;

	tok = main->tok_head;
	cmd_set = false;
	while (tok)
	{
		target = NULL;
		if (tok->type == OPERATOR && f_strcmp(tok->str, "|") == 0)
			cmd_set = false;
		else if (tok->type == WORD && tok->prev && tok->prev->type == OPERATOR
			&& f_strcmp(tok->prev->str, "|") != 0 && tok->prev->args == NULL)
			target = tok->prev;
		else if (tok->type == WORD && cmd_set == false)
		{
			tok->type = COMMAND;
			cmd_set = true;
		}
		else if (tok->type == WORD && cmd_set == true)
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
		tok = tok->next;
	}
}
