/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:55:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 14:44:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Main loop runs as long as readline returns a line (i.e. until Ctrl-D is
received). In the loop: First the readline return is added to gc, so that it
will later be freed. Then non-empty lines will be added to the readline-builtin-
history. Then tokenization happens. After that there is a list of tokens
(commands and operators). f_execute is only a placeholder until we have proper
execution. It executes the first command of the token list, if it is a builtin.
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
			exit(1);
		if (main.user_input && *main.user_input)
			add_history(main.user_input);
		f_tokenize(&main);
		f_execute(&main);
		main.user_input = readline(PROMPT);
	}
	printf("Minishell closed because readline() received EOF\n");
	f_gc_clean(&main);
	return (0);
}
