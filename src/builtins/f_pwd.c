/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:35:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 15:55:59 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_pwd(char *env[])
{
	int	i;

	i = 0;
	while (strncmp(env[i], "PWD=", 4) != 0)
		i++;
	printf("Working directory: %s\n", env[i] + 4);
	return ;
}
