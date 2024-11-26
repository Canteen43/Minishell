/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:10:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/26 10:45:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initializer function*/
void	init(t_main *main, char *env[])
{
	main->gc_head = NULL;
	main->env_head = NULL;
	main->exit_status = 0;
	main->env_head = NULL;
	f_env_create_lnklst(main, env);
	f_handle_signals();
}
