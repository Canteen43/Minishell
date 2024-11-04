/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:27:05 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_execute(char *line, t_main *main)
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
		f_env(main);
	if (strncmp(line, "cd ", 3) == 0)
		f_cd(line + 3);
}
