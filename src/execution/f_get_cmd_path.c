/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:14:15 by glevin            #+#    #+#             */
/*   Updated: 2024/12/11 16:56:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*f_get_cmd_path(t_main *main, char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp_path;

	i = -1;
	if (!paths || !cmd)
		return (NULL);
	if ((strncmp(cmd, "/", 1) == 0 || strncmp(cmd, "./", 2) == 0 || strncmp(cmd,
				"../", 3) == 0 || cmd[0] == '/') && access(cmd, X_OK) == 0)
		return (cmd);
	while (paths[++i])
	{
		tmp_path = f_strjoin(main, paths[i], "/");
		cmd_path = f_strjoin(main, tmp_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
	}
	return (NULL);
}
