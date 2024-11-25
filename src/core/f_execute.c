/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 15:02:00 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execute(t_main *main)
{
	t_tok	*tok;

	tok = main->tok_head;
	if (strcmp(tok->str, "echo") == 0)
		f_echo(main);
	else if (strcmp(tok->str, "pwd") == 0)
		f_pwd(main);
	else if (strcmp(tok->str, "exit") == 0)
		f_free_and_exit(main, "Exiting Minishell", 0);
	else if (strcmp(tok->str, "env") == 0)
		f_env(main);
	else if (strcmp(tok->str, "cd") == 0)
		f_cd(main);
	else if (strcmp(tok->str, "unset") == 0)
		f_unset(main);
	else if (strcmp(tok->str, "export") == 0)
		f_export(main);
	else
		printf("Command not found: %s\n", tok->str);
}
