/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_increase_shlvl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:35:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/07 09:55:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_increase_shlvl(t_main *main)
{
	t_env	*node;
	int		cur_shlvl;

	node = f_env_find_key(main->env_head, "SHLVL");
	if (!node)
		return ;
	if (f_atoi_mod(node->value, &cur_shlvl) == -1)
		return ;
	node->value = f_itoa(main, cur_shlvl + 1);
}
