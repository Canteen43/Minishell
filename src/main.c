/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/12 16:09:56 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;
	char	*command_line;

	(void)argc;
	(void)argv;
	init(&main, env);
	command_line = readline(PROMPT);
	while (command_line)
	{
		f_extract_cmd(&main, command_line);
		f_execute(&main);
		free(command_line);
		command_line = readline(PROMPT);
	}
	printf("Minishell closed because readline() received EOF\n");
	return (0);
}
