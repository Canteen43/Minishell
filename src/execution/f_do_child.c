/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:31:54 by glevin            #+#    #+#             */
/*   Updated: 2024/12/10 16:28:27 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_do_child(t_main *main, t_pipex *pipex, t_tok *tok, int is_final)
{
	if (tok->redir_head)
		f_set_redirects(pipex, main, tok);
	if (pipex->infile != -1)
	{
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	if (pipex->outfile != -1)
	{
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	else if (is_final)
		dup2(main->stdout_copy, STDOUT_FILENO);
	else
		dup2(pipex->fd[1], STDOUT_FILENO);
	f_do_execute(main, pipex, tok);
	close(pipex->fd[0]);
}
