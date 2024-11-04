/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:28:53 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_unset(t_main *main, char *str)
{
	t_env	*node;

	node = f_env_find_key(main->env_head, str);
	if (node)
		f_env_del_one(&main->env_head, node);
	else
		printf("No match found for key.");
}
