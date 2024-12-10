/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_resolve_heredocs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:24:30 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 16:32:33 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static bool	sf_upcoming_input(t_tok *tok);

int	f_resolve_heredocs(t_main *main)
{
	t_tok	*cmd;
	t_tok	*redir;
	t_tok	*next;

	cmd = main->tok_head;
	while (cmd)
	{
		redir = cmd->redir_head;
		while (redir)
		{
			next = redir->next;
			if (redir->type == REDIR_HEREDOC && f_do_heredoc(main, redir) == 1)
				return (1);
			if (redir->type == REDIR_HEREDOC && sf_upcoming_input(redir))
			{
				close(redir->heredoc_fd);
				f_tok_remove_one_universal(&cmd->redir_head, redir);
			}
			redir = next;
		}
		cmd = cmd->next;
	}
	return (0);
}

static bool	sf_upcoming_input(t_tok *tok)
{
	tok = tok->next;
	while (tok)
	{
		if (tok->type == REDIR_HEREDOC || tok->type == REDIR_IN)
			return (true);
		tok = tok->next;
	}
	return (false);
}
