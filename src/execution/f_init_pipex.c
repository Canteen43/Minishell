/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:45:19 by glevin            #+#    #+#             */
/*   Updated: 2024/11/24 12:26:03 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	init_pipex(t_pipex *pipex, t_main *main)
{
	char *paths;
	t_env *c_env;

	c_env = main->env_head;
	while (f_strncmp("PATH", c_env->key, 4))
		c_env = c_env->next;
	pipex->paths = f_split(c_env->value, ':');
    
}
