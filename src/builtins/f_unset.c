/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:28:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/27 18:23:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_unset(t_main *main)
{
	t_env	*node;
	char	**args;

	args = main->tok_head->args;
	args++;
	while (*args)
	{
		node = f_env_find_key(main->env_head, *args);
		if (node)
			f_env_remove_one(main, node);
		else
			printf("No match found for key |%s|.\n", *args);
		args++;
	}
}
