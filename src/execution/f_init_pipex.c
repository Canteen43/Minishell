/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:45:19 by glevin            #+#    #+#             */
/*   Updated: 2024/12/04 10:16:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Sets up pipex->paths (split() of PATH) and pipex->envp (2d-array create from
env*/
void	f_init_pipex(t_pipex *pipex, t_main *main)
{
	t_env	*c_env;

	c_env = main->env_head;
	while (f_strncmp("PATH", c_env->key, 4))
		c_env = c_env->next;
	pipex->paths = f_split(main, c_env->value, ':');
	pipex->envp = f_env_create_2da(main);
	pipex->stdfd[0] = dup(STDIN_FILENO);
	pipex->stdfd[1] = dup(STDOUT_FILENO);
}
