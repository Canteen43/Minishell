/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_redirs_to_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/11 11:24:43 by kweihman         ###   ########.fr       */
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
	current_cmd = NULL;
	while (tok)
	{
		next = tok->next;
		if (tok->type == PIPE)
			current_cmd = NULL;
		else if (current_cmd == NULL)
			current_cmd = sf_next_command(main, tok);
		if (f_tok_is_redir(tok))
			sf_add_redir_to_cmd(main, tok, current_cmd);
		tok = next;
	}
}

static t_tok	*sf_next_command(t_main *main, t_tok *tok)
{
	t_tok	*new;

	if (tok->type == COMMAND)
		return (tok);
	while (tok->next && tok->next->type != COMMAND && tok->next->type != PIPE)
		tok = tok->next;
	if (tok->next && tok->next->type == COMMAND)
		return (tok->next);
	else
	{
		new = f_tok_new(main, NULL);
		new->type = COMMAND;
		new->next = tok->next;
		new->prev = tok;
		tok->next = new;
	}
	return (new);
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
