/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:28:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 15:27:30 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_unset(t_main *main)
{
	t_env	*node;
	char	**args;

	args = main->current_cmd.args;
	args++;
	while (*args)
	{
		node = f_env_find_key(main->env_head, *args);
		if (node)
			f_env_del_one(&main->env_head, node);
		else
			printf("No match found for key |%s|.\n", *args);
		args++;
	}
}
