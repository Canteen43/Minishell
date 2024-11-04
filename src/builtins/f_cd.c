/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 09:34:05 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_cd(char *path, t_main *main)
{
	
	if (chdir(path) == -1)
		printf("Changing directory unsuccessful.\n");
	f_env_find_key(main->env_head, "OLDPWD")->value
	= f_env_find_key(main->env_head, "PWD")->value;
	f_env_find_key(main->env_head, "PWD")->value = getcwd(NULL, 0);
	return ;
}
