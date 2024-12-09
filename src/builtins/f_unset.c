/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:28:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:06:21 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_unset(t_main *main, t_tok *tok)
{
	t_env	*node;
	char	**args;

	args = tok->args;
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
