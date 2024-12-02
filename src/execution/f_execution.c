/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 11:33:39 by kweihman         ###   ########.fr       */
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
	dup2(pipex.infile, STDIN_FILENO);
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
