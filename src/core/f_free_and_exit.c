/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:03:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/11 16:41:17 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Function to exit print an exit message, free everything with gc and exit.*/
void	f_free_and_exit(t_main *main, char *message, int code)
{
	f_gc_clean(main);
	if (message)
	{
		write(STDERR_FILENO, message, f_strlen(message));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(code);
}
