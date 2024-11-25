/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:27:10 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 14:50:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_env_add_back(t_main *main, char *key, char *value)
{
	t_env	*new;

	new = f_env_new(main, key, value);
	if (main->env_head == NULL)
		main->env_head = new;
	else
		f_env_last(main->env_head)->next = new;
}
