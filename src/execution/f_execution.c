/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/12/15 16:22:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execution(t_main *main)
{
	t_pipex	pipex;
	t_tok	*tok;

	f_init_pipex(&pipex, main);
	tok = main->tok_head;
	if (tok->next == NULL)
		f_handle_single_cmd(main, &pipex, tok);
	else
	{
		f_signal_setup(SIGMODE_WAITFORCHILD);
		while (tok)
		{
			if (tok->next == NULL)
				f_handle_final_cmd(main, &pipex, tok);
			else if (tok->type == COMMAND)
				f_handle_cmd(main, &pipex, tok);
			tok = tok->next;
			pipex.infile = -1;
			pipex.outfile = -1;
		}
	}
	dup2(main->stdin_copy, STDIN_FILENO);
	dup2(main->stdout_copy, STDOUT_FILENO);
	return ;
}
