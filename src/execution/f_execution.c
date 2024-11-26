/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/11/25 19:14:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	final_execute(t_pipex *pipex, int argc, char **argv, char **envp)
void	f_final_execute(t_main *main, t_pipex *pipex, t_tok *c_tok, char **envp)
{
	int	status;

	dup2(pipex->outfile, STDOUT_FILENO);
	f_do_execute(main, pipex, c_tok, envp);
	while (wait(&status) > 0)
		f_exit_clean(pipex, 0);
}

t_tok	*f_find_final_cmd(t_main *main)
{
	t_tok	*c_tok;
	t_tok	*final_cmd_tok;

	c_tok = main->tok_head;
	while (c_tok)
	{
		if (c_tok->type == COMMAND)
			final_cmd_tok = c_tok;
		c_tok = c_tok->next;
	}
	return (final_cmd_tok);
}

// int	f_execution(int argc, char **argv, char **envp)
void	f_execution(t_main *main, char **envp)
{
	t_pipex	pipex;
	t_tok	*c_tok;
	t_tok	*final_cmd_tok;

	f_init_pipex(&pipex, main);
	f_set_redirects(&pipex, main);
	dup2(pipex.infile, 0);
	final_cmd_tok = f_find_final_cmd(main);
	c_tok = main->tok_head;
	while (c_tok)
	{
		if (c_tok == final_cmd_tok)
			break ;
		if (c_tok->type == COMMAND)
			f_do_pipe(main, &pipex, c_tok, envp);
		c_tok = c_tok->next;
	}
	f_final_execute(main, &pipex, c_tok, envp);
	return ;
}
