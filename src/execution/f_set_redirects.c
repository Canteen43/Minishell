/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:01:04 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 10:54:59 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_set_redirects(t_pipex *pipex, t_main *main)
{
	t_tok	*tok;
	t_tok	*next_tok;

	tok = main->tok_head;
	while (tok)
	{
		if (f_strcmp(tok->str, ">") == 0)
		{
			pipex->outfile = f_open_file(pipex, tok->args[0], 2);
			next_tok = tok->next;
			f_tok_remove_one_universal(main, tok);
			tok = next_tok;
		}
		else if (f_strcmp(tok->str, "<") == 0)
		{
			pipex->infile = f_open_file(pipex, tok->args[0], 1);
			next_tok = tok->next;
			f_tok_remove_one_universal(main, tok);
			tok = next_tok;
		}
		else
			tok = tok->next;
	}
}
