/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:04:07 by glevin            #+#    #+#             */
/*   Updated: 2024/11/24 12:26:53 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	final_execute(t_pipex pipex, int argc, char **argv, char **envp)
{
	int	status;

	dup2(pipex.outfile, STDOUT_FILENO);
	f_do_execute(&pipex, argv[argc - 2], envp);
	while (wait(&status) > 0)
		f_exit_clean(&pipex, 0);
}

// int	f_execution(int argc, char **argv, char **envp)
int	f_execution(t_main *main)
{
	t_pipex	pipex;
	int		i;
	t_tok	*c_tok;

	init_pipex(&pipex, main);
	f_set_redirects(&pipex, main);
	dup2(pipex.infile, 0);
	i = 2;
	c_tok = main->tok_head;
	while (c_tok)
	{
		if (!f_strncmp("CMD", c_tok->str, 3))
			f_do_pipe(&pipex, envp, argv[i++]);
		c_tok->next;
	}
	final_execute(pipex, argc, argv, envp);
	return (0);
}
