/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:19:20 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/28 08:21:21 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	f_echo(int argc, char **argv, char **envp)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		fl_miniprint("%s", argv[i]);
		if (i + 1 < argc)
			fl_miniprint(" ");
		i++;
	}
	fl_miniprint("\n");
}
