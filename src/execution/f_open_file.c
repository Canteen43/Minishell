/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:13:20 by glevin            #+#    #+#             */
/*   Updated: 2024/12/11 16:39:20 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_open_file(t_pipex *pipex, char *filename, int i)
{
	int	fd;

	(void)pipex;
	fd = 0;
	if (i == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (i == 1)
		fd = open(filename, O_RDONLY);
	else if (i == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		fd = -2;
		if (errno == EACCES)
			write(2, PERMDENIED, f_strlen(PERMDENIED));
		else if (errno == ENOENT)
			write(2, MISSINGFILEFAIL, f_strlen(MISSINGFILEFAIL));
		else
			write(2, GENERICFILEFAIL, f_strlen(GENERICFILEFAIL));
	}
	return (fd);
}
