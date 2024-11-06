/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 14:34:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execute(t_main *main)
{
	if (strcmp(main->current_cmd.command, "echo") == 0)
		f_echo(main);
	else if (strcmp(main->current_cmd.command, "pwd") == 0)
		f_pwd();
	else if (strcmp(main->current_cmd.command, "exit") == 0)
	{
		printf("Exiting Minishell");
		exit(0);
	}
	else if (strcmp(main->current_cmd.command, "env") == 0)
		f_env(main);
	else if (strcmp(main->current_cmd.command, "cd") == 0)
		f_cd(main);
	else if (strcmp(main->current_cmd.command, "unset") == 0)
		f_unset(main);
	else if (strcmp(main->current_cmd.command, "export") == 0)
		f_export(main);
	else
		printf("Command not found: %s\n", main->current_cmd.command);
}
