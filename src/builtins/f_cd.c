/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/03 12:16:15 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_cd(char *path)
{
	if (chdir(path) == -1)
		printf("Changing directory unsuccessful.\n");
	return ;
}
