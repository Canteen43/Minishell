/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:03:19 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 16:09:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_var_index(char *str, int *start, int *end)
{
	int	i;

	i = 0;
	*start = -1;
	*end = -1;
	while (str[i])
	{
		if (str[i] == '$')
			*start = i + 1;
		

	}
		i++;
	*start = i;
	while (str[i] && str[i] != ' ')
		i++;
	*end = i;
}