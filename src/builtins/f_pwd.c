/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:35:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 15:04:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_pwd(t_main *main)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		f_free_and_exit(main, "getcwd() failed", 1);
	if (!f_gc_add_node(main, path))
		f_free_and_exit(main, MALLOCFAIL, 1);
	printf("%s\n", path);
}
