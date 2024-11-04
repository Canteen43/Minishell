/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 10:52:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;
	char	*command_line;

	(void)argc;
	(void)argv;
	main.env_head = f_env_create_lnklst(env);
	f_handle_signals();
	command_line = readline("Enter command: ");
	while (command_line)
	{
		f_execute(command_line, &main);
		free(command_line);
		command_line = readline("Enter another command: ");
	}
	printf("Minishell closed because readline() received EOF");
	return (0);
}
