/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:10:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/02 10:19:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initializer function*/
void	init(t_main *main, char *env[])
{
	f_signal_setup(SIGMODE_INTERACTIVE);
	main->gc_head = NULL;
	main->env_head = NULL;
	main->exit_status = 0;
	main->env_head = NULL;
	f_env_create_lnklst(main, env);
}
