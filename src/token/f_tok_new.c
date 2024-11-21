/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:45:18 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/17 10:28:29 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*f_tok_new(char *str)
{
	t_tok	*new;

	new = (t_tok *)malloc(sizeof(t_tok));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->type = NONE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}