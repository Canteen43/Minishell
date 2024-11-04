/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:22:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;
	char	*command_line;

	main.env_head = f_env_create_2da(env);
	f_handle_signals();
	printf("Argc: %d, Argv[0]: %s\n", argc, argv[0]);
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
