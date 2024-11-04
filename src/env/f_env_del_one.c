/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_del_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:39:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 08:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Deletes one node of a linked list of env variables. */
void	f_env_del_one(t_env **p_head, t_env *node)
{
	t_env	*tmp;

	if (*p_head == node)
	{
		*p_head = node->next;
		free(node->key);
		free(node->value);
		free(node);
	}
	else
	{
		tmp = *p_head;
		while (tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
		free(node->key);
		free(node->value);
		free(node);
	}
}
