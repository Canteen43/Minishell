/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_final_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:49:55 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 10:50:09 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_final_execute(t_main *main, t_pipex *pipex, t_tok *tok)
{
	int	status;

	dup2(pipex->outfile, STDOUT_FILENO);
	f_do_execute(main, pipex, tok);
	while (wait(&status) > 0)
		exit(0);
}
