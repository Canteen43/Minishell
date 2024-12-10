/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_redirs_to_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/10 17:39:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static t_tok	*sf_next_command(t_main *main, t_tok *tok);
static void		sf_add_redir_to_cmd(t_main *main, t_tok *redir_tok,
					t_tok *cmd_tok);

void	f_add_redirs_to_cmds(t_main *main)
{
	t_tok	*tok;
	t_tok	*next;
	t_tok	*current_cmd;

	tok = main->tok_head;
	current_cmd = sf_next_command(main, tok);
	while (tok)
	{
		next = tok->next;
		if (tok->type == PIPE)
			current_cmd = sf_next_command(main, tok);
		else if (f_tok_is_redir(tok))
			sf_add_redir_to_cmd(main, tok, current_cmd);
		tok = next;
	}
}

static t_tok	*sf_next_command(t_main *main, t_tok *tok)
{
	while (tok && tok->type != COMMAND)
		tok = tok->next;
	if (tok == NULL)
	{
		tok = f_tok_new(main, NULL);
		tok->type = COMMAND;
	}
	return (tok);
}

static void	sf_add_redir_to_cmd(t_main *main, t_tok *redir_tok, t_tok *cmd_tok)
{
	t_tok	*last_redir_tok;

	f_tok_remove_one_universal(&main->tok_head, redir_tok);
	last_redir_tok = f_tok_last(cmd_tok->redir_head);
	if (!last_redir_tok)
		cmd_tok->redir_head = redir_tok;
	else
		last_redir_tok->next = redir_tok;
	redir_tok->prev = last_redir_tok;
	redir_tok->next = NULL;
}
