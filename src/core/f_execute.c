/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/03 12:14:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execute(char *line, char *env[])
{
	if (strncmp(line, "echo ", 5) == 0)
		printf("%s\n", line + 5);
	if (strcmp(line, "pwd") == 0)
		f_pwd();
	if (strcmp(line, "exit") == 0)
	{
		printf("Exiting Minishell");
		exit(0);
	}
	if (strcmp(line, "env") == 0)
		f_env(env);
	if (strncmp(line, "cd ", 3) == 0)
		f_cd(line + 3);
}
