/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:19:20 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 14:39:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	f_echo(int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i + 1 < argc)
			printf(" ");
		i++;
	}
	printf("\n");
}
