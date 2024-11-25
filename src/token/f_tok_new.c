/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:45:18 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:29:57 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*f_tok_new(t_main *main, char *str)
{
	t_tok	*new;

	new = (t_tok *)f_gc_malloc(main, sizeof(t_tok));
	if (!new)
		f_free_and_exit(main, MALLOCFAIL, 1);
	new->str = str;
	new->type = NONE;
	new->prev = NULL;
	new->next = NULL;
	new->args = NULL;
	return (new);
}
