/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/02 10:44:59 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_execute_builtin(t_main *main, t_tok *tok)
{
	int		is_builtin;

	is_builtin = 1;
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
		is_builtin = 0;
	return (is_builtin);
}
