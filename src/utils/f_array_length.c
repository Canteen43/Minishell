/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_array_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:00:56 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 16:04:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_array_length(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}
