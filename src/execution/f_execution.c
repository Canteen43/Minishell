/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/12/07 14:07:58 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execution(t_main *main)
{
	t_pipex	pipex;
	t_tok	*tok;
	t_tok	*final_cmd_tok;

	f_init_pipex(&pipex, main);
	final_cmd_tok = f_find_final_cmd(main);
	tok = main->tok_head;
	while (tok)
	{
		if (tok == final_cmd_tok)
			f_do_pipe(main, &pipex, tok, 1);
		if (tok->type == COMMAND)
			f_do_pipe(main, &pipex, tok, 0);
		tok = tok->next;
	}
	dup2(main->stdin_copy, STDIN_FILENO);
	dup2(main->stdout_copy, STDOUT_FILENO);
	return ;
}
