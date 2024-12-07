/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/12/06 18:24:08 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execution(t_main *main)
{
	t_pipex	pipex;
	t_tok	*tok;
	t_tok	*final_cmd_tok;

	f_print_tokens(main);
	// printf("HERER");
	f_init_pipex(&pipex, main);
	
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
	dup2(main->stdin_copy, STDIN_FILENO);
	dup2(main->stdout_copy, STDOUT_FILENO);
	return ;
}
