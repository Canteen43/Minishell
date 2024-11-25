/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:01:04 by glevin            #+#    #+#             */
/*   Updated: 2024/11/25 14:36:49 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_set_redirects(t_pipex *pipex, t_main *main)
{
	t_tok	*c_tok;

	c_tok = main->tok_head;
	while (c_tok)
	{
		if (f_strcmp(c_tok->str, ">") == 0)
			pipex->outfile = f_open_file(pipex, c_tok->args[0], 2);
		else if (f_strcmp(c_tok->str, "<") == 0)
			pipex->infile = f_open_file(pipex, c_tok->args[0], 1);
		c_tok = c_tok->next;
	}
}
