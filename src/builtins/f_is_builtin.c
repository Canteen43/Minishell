/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:31:19 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 14:34:00 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *command)
{
	if (f_strcmp(command, "echo") == 0)
		return (1);
	if (f_strcmp(command, "cd") == 0)
		return (1);
	if (f_strcmp(command, "pwd") == 0)
		return (1);
	if (f_strcmp(command, "env") == 0)
		return (1);
	if (f_strcmp(command, "export") == 0)
		return (1);
	if (f_strcmp(command, "unset") == 0)
		return (1);
	return (0);
}
