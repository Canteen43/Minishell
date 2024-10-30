/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 15:35:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char *line, char *env[])
{
	if (strncmp(line, "echo ", 5) == 0)
		printf("", line + 5);
	if (strcmp(line, "pwd") == 0)
		f_pwd(env);
	if (strcmp(line, "exit") == 0)
	{
		printf("Exiting Minishell");
		exit(0);
	}
}
