/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:19:20 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/15 18:11:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	f_echo(t_main *main, t_tok *tok)
{
	char	**args;
	int		i;
	bool	n_flag;

	n_flag = false;
	args = tok->args;
	i = 1;
	if (args[1] && strcmp(args[1], "-n") == 0)
	{
		n_flag = true;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	main->exit_status = 0;
	return ;
}
