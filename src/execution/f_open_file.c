/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:13:20 by glevin            #+#    #+#             */
/*   Updated: 2024/12/10 12:38:06 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_open_file(t_pipex *pipex, char *filename, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (i == 1)
		fd = open(filename, O_RDONLY);
	else if (i == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("\033[31mError\033[0m");
		f_exit_clean(pipex, 1);
	}
	return (fd);
}
