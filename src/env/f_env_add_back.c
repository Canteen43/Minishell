/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:27:10 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:51:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_env_add_back(t_env **p_head, char *key, char *value)
{
	t_env	*new;

	new = f_env_new(key, value);
	if (new == NULL)
		return (-1);
	if (*p_head == NULL)
		*p_head = new;
	else
		f_env_last(*p_head)->next = new;
	return (0);
}
