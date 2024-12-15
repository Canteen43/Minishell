/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:52:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/15 17:53:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_env(t_main *main)
{
	t_env	*env;

	env = main->env_head;
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	main->exit_status = 0;
}
