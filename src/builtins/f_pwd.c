/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:35:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 09:34:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		exit(1);
	printf("%s\n", path);
	free(path);
	return ;
}
