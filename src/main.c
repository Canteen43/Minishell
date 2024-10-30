/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Too few arguments.\n");
		exit(1);
	}
	if (f_strcmp(argv[1], "echo") == 0)
		f_echo(argc, argv);
	else
	{
		printf("Command not found.\n");
		exit(1);
	}
	return (0);
}
