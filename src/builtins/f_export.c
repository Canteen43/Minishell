/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_export(t_main *main, char *str)
{
	char	*key;
	char	*value;

	if (!f_strchr(str, '='))
	{
		f_env_add_back(&main->env_head, f_strjoin("", str), "\0");
		return ;
	}
	key = f_env_strtokey(str);
	value = f_env_strtovalue(str);
	if (key == NULL || value == NULL)
		return ;
	f_env_add_back(&main->env_head, key, value);
}
