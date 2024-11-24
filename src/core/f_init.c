/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:10:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/24 10:36:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_main *main, char *env[])
{
	main->env_head = NULL;
	main->exit_status = 0;
	main->env_head = f_env_create_lnklst(env);
	main->gc = NULL;
	f_handle_signals();
}
