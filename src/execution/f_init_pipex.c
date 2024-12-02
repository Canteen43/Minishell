/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:45:19 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 11:22:30 by kweihman         ###   ########.fr       */
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
}
