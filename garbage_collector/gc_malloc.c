/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:16:46 by glevin            #+#    #+#             */
/*   Updated: 2024/11/21 14:00:44 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to add a node to the garbage collector list
void	add_node(void *ptr, t_gc *gc)
{
	t_gnode	*new_node;

	new_node = (t_gnode *)malloc(sizeof(t_gnode));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = gc->head;
	gc->head = new_node;
}

// Wrapper for malloc that integrates with garbage collector
void	*gc_malloc(size_t size, t_gc *gc)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	add_node(ptr, gc);
	return (ptr);
}
