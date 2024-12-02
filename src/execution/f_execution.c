/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 10:53:01 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execution(t_main *main)
{
	t_pipex	pipex;
	t_tok	*tok;
	t_tok	*final_cmd_tok;

	f_init_pipex(&pipex, main);
	f_set_redirects(&pipex, main);
	final_cmd_tok = f_find_final_cmd(main);
	dup2(pipex.infile, 0);
	tok = main->tok_head;
	while (tok)
	{
		if (tok == final_cmd_tok)
			break ;
		if (tok->type == COMMAND)
			f_do_pipe(main, &pipex, tok);
		tok = tok->next;
	}
	f_final_execute(main, &pipex, tok);
	return ;
}
