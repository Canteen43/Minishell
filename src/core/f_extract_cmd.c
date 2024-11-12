/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_extract_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:45:45 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/06 13:27:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_extract_cmd(t_main *main, char *command_line)
{
	char	**arr;

	arr = f_split(command_line, ' ');
	main->current_cmd.command = arr[0];
	main->current_cmd.args = arr;
}
