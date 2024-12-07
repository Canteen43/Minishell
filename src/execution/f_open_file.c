/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:13:20 by glevin            #+#    #+#             */
/*   Updated: 2024/12/07 13:46:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_open_file(t_pipex *pipex, char *filename, int i)
{
	int	fd;

	printf("filename: %s\n", filename);
	fd = 0;
	if (i == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (i == 1)
		fd = open(filename, O_RDONLY);
	else if (i == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("\033[31mError");
		f_exit_clean(pipex, 1);
	}
	return (fd);
}
