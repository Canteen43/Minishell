/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:03:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:38:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Function to exit print an exit message, free everything with gc and exit.*/
void	f_free_and_exit(t_main *main, char *message, int code)
{
	fprintf(stdout, "%s\n", message);
	f_gc_clean(main);
	exit (code);
}
