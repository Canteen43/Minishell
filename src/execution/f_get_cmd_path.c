/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:14:15 by glevin            #+#    #+#             */
/*   Updated: 2024/11/21 14:26:49 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*f_get_cmd_path(char **paths, char *in_cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp_path;

	i = -1;
	if (!paths || !in_cmd)
	{
		return (NULL);
	}
	if (access(in_cmd, X_OK | F_OK) == 0)
		return (in_cmd);
	while (paths[++i])
	{
		tmp_path = f_strjoin(paths[i], "/");
		cmd_path = f_strjoin(tmp_path, in_cmd);
		free(tmp_path);
		if (access(cmd_path, X_OK | F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}
