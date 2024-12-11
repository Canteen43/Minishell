/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 15:36:02 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_do_builtin(t_main *main, t_tok *tok)
{
	int	is_builtin;

	if (tok->str == NULL)
		return (0);
	is_builtin = 1;
	if (strcmp(tok->str, "echo") == 0)
		f_echo(tok);
	else if (strcmp(tok->str, "pwd") == 0)
		f_pwd(main);
	else if (strcmp(tok->str, "exit") == 0)
		f_exit(main, tok);
	else if (strcmp(tok->str, "env") == 0)
		f_env(main);
	else if (strcmp(tok->str, "cd") == 0)
		f_cd(main, tok);
	else if (strcmp(tok->str, "unset") == 0)
		f_unset(main, tok);
	else if (strcmp(tok->str, "export") == 0)
		f_export(main, tok);
	else
		is_builtin = 0;
	return (is_builtin);
}
