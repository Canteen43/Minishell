/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:55:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/15 17:12:31 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	g_prompt_int_caught;

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;

	(void)argc;
	(void)argv;
	init(&main, env);
	while (1)
	{
		g_prompt_int_caught = false;
		main.user_input = readline(PROMPT);
		if (g_prompt_int_caught)
			main.exit_status = 130;
		if (!main.user_input)
			break ;
		if (f_gc_add_node(&main, main.user_input) == NULL)
			f_free_and_exit(&main, MALLOCFAIL, 1);
		if (!*main.user_input)
			continue ;
		add_history(main.user_input);
		if (f_tokenize(&main) == 1)
			continue ;
		if (f_resolve_heredocs(&main) == 1)
			continue ;
		f_execution(&main);
	}
	f_exit(&main, NULL);
}
