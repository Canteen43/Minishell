/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 10:39:44 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;

	(void)argc;
	(void)argv;
	init(&main, env);
	main.user_input = readline(PROMPT);
	while (main.user_input)
	{
		if (main.user_input && *main.user_input)
			add_history(main.user_input);
		f_tokenize(&main);
		f_execute(&main);
		if (f_gc_add_node(&main, main.user_input) == NULL)
			exit(1);
		main.user_input = readline(PROMPT);
	}
	printf("Minishell closed because readline() received EOF\n");
	return (0);
}
