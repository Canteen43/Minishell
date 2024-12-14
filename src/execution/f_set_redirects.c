/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:01:04 by glevin            #+#    #+#             */
/*   Updated: 2024/12/14 14:32:04 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Sets up pipex->infile and pipex->outfile by iterating through the redirect
list of a given CMD token.*/

static void	sf_set_redir_out(t_pipex *pipex, t_tok *tok);
static void	sf_set_redir_in(t_pipex *pipex, t_tok *tok);
static void	sf_set_redir_out_append(t_pipex *pipex, t_tok *tok);
static void	sf_set_redir_heredoc(t_pipex *pipex, t_tok *tok);

void	f_set_redirects(t_pipex *pipex, t_tok *tok)
{
	tok = tok->redir_head;
	while (tok)
	{
		if (tok->type == REDIR_IN)
			sf_set_redir_in(pipex, tok);
		else if (tok->type == REDIR_OUT)
			sf_set_redir_out(pipex, tok);
		else if (tok->type == REDIR_OUT_APP)
			sf_set_redir_out_append(pipex, tok);
		else if (tok->type == REDIR_HEREDOC)
			sf_set_redir_heredoc(pipex, tok);
		if (pipex->infile == -2 || pipex->outfile == -2)
			return ;
		tok = tok->next;
	}
}

static void	sf_set_redir_in(t_pipex *pipex, t_tok *tok)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	pipex->infile = f_open_file(pipex, tok->args[0], 1);
}

static void	sf_set_redir_out(t_pipex *pipex, t_tok *tok)
{
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	pipex->outfile = f_open_file(pipex, tok->args[0], 2);
}

static void	sf_set_redir_out_append(t_pipex *pipex, t_tok *tok)
{
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	pipex->outfile = f_open_file(pipex, tok->args[0], 0);
}

static void	sf_set_redir_heredoc(t_pipex *pipex, t_tok *tok)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	pipex->infile = tok->heredoc_fd;
}
