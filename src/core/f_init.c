/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:10:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 14:53:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initializer function*/
void	init(t_main *main, char *env[])
{
	main->env_head = NULL;
	main->exit_status = 0;
	main->env_head = NULL;
	f_env_create_lnklst(main, env);
	main->gc_head = NULL;
	f_handle_signals();
}
