/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:00:37 by glevin            #+#    #+#             */
/*   Updated: 2024/11/24 10:42:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to clean all allocated memory in the garbage collector
void	gc_clean(t_gc *gc)
{
	t_gnode	*tmp;
	t_gnode	*current;

	current = gc->head;
	while (current)
	{
		free(current->ptr);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	gc->head = NULL;
}
