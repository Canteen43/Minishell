/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_remove_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:39:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 15:24:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Deletes one node of a linked list of env variables. */
void	f_env_remove_one(t_main *main, t_env *node)
{
	t_env	*tmp;

	if (node == main->env_head)
		main->env_head = node->next;
	else
	{
		tmp = main->env_head;
		while (tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
	}
}
