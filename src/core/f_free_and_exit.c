/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:03:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/16 10:33:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Function to exit print an exit message, free everything with gc and exit.*/
void	f_free_and_exit(t_main *main, char *message, int code)
{
	close(main->stdin_copy);
	close(main->stdout_copy);
	f_gc_clean(main);
	if (message)
	{
		write(STDERR_FILENO, message, f_strlen(message));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(code);
}
