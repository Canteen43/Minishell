/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:55:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 19:33:37 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Main loop runs as long as readline returns a line (i.e. until Ctrl-D is
received). In the loop: First the readline return is added to gc, so that it
will later be freed. Then non-empty lines will be added to the readline-builtin-
history. Then tokenization happens. After that there is a list of tokens
(commands and operators).
*/

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;

	(void)argc;
	(void)argv;
	init(&main, env);
	main.user_input = readline(PROMPT);
	while (main.user_input)
	{
		if (f_gc_add_node(&main, main.user_input) == NULL)
			f_free_and_exit(&main, MALLOCFAIL, 1);
		if (main.user_input && *main.user_input)
			add_history(main.user_input);
		if (f_tokenize(&main) == 0)
			f_execution(&main);
		main.user_input = readline(PROMPT);
	}
	printf("Minishell closed because readline() received EOF, i.e. Ctrl-D\n");
	f_gc_clean(&main);
	return (0);
}
