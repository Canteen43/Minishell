/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_redirs_to_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:01:25 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:07:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static t_tok	*sf_next_command(t_tok *tok);
static void		sf_add_redir_to_cmd(t_main *main, t_tok *redir_tok,
					t_tok *cmd_tok);

void	f_add_redirs_to_cmds(t_main *main)
{
	t_tok	*tok;
	t_tok	*tmp;
	t_tok	*current_cmd;

	tok = main->tok_head;
	current_cmd = sf_next_command(tok);
	while (tok)
	{
		tmp = tok;
		tok = tok->next;
		if (tmp->type == PIPE)
			current_cmd = sf_next_command(tmp);
		else if (f_tok_is_redir(tmp))
			sf_add_redir_to_cmd(main, tmp, current_cmd);
	}
}

static t_tok	*sf_next_command(t_tok *tok)
{
	while (tok && tok->type != COMMAND)
		tok = tok->next;
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
