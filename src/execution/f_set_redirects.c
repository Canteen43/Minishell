/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:01:04 by glevin            #+#    #+#             */
/*   Updated: 2024/12/07 14:10:28 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Sets up pipex->infile and pipex->outfile by iterating through the redirect list
of a given CMD token*/

void	f_set_redirects(t_pipex *pipex, t_main *main, t_tok *tok)
{
	tok = tok->redir_head;
	(void)main;
	while (tok)
	{
		if (tok->type == REDIR_IN)
		{
			if (pipex->infile > 0)
				close(pipex->infile);
			pipex->infile = f_open_file(pipex, tok->args[0], 1);
		}
		else if (tok->type == REDIR_OUT)
		{
			if (pipex->outfile != 0)
				close(pipex->outfile);
			pipex->outfile = f_open_file(pipex, tok->args[0], 2);
		}
		else if (tok->type == REDIR_OUT_APP)
		{
			if (pipex->outfile != 0)
				close(pipex->outfile);
			pipex->outfile = f_open_file(pipex, tok->args[0], 0);
		}
		// else if (tok->type == REDIR_HEREDOC)
		// {
		// 	f_here_doc(pipex, tok->args[0], main->current_cmd.argc);
		// }
		tok = tok->next;
	}
	if (pipex->infile)
		dup2(pipex->infile, STDIN_FILENO);
	if (pipex->outfile)
		dup2(pipex->outfile, STDOUT_FILENO);
}
