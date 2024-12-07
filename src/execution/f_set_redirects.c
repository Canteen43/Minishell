/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:01:04 by glevin            #+#    #+#             */
/*   Updated: 2024/12/06 18:31:01 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* TODO: This version only checks the string of the current token without
checking the type. However, ">" could also just be a word and not an operator*/

/*Sets up pipex->infile and pipex->outfile by iterating through the whole
token list*/
void	f_set_redirects(t_pipex *pipex, t_main *main, t_tok *tok)
{
	tok = main->tok_head->redir_head;
	while (tok)
	{
		if (tok->type == REDIR_IN)
		{
			printf("REDIR_IN\n");
			if (pipex->infile != 0)
				close(pipex->infile);
			printf("REDIR_IN\n");
			printf("tok->str: %s\n", tok->str);
			printf("tok->args[0]: %s\n", *(tok->args));
			pipex->infile = f_open_file(pipex, tok->args[0], 1);
			printf("REDIR_IN\n");
		}
		else if (tok->type == REDIR_OUT)
		{
			printf("REDIR_OUT\n");
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
}
