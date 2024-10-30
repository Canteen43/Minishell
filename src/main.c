/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 15:35:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*command_line;

	printf("Argc: %d, Argv[0]: %s", argc, argv[0]);
	command_line = readline("Enter command: ");
	while (command_line)
	{
		f_execute(command_line, env);
		free(command_line);
		command_line = readline("Enter another command: ");
	}
	printf("Minishell closed because readline() received EOF");
	return (0);
}
