/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:27:10 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/13 09:07:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_tok_add_back(t_tok **p_head, char *str)
{
	t_tok	*new;
	t_tok	*last;

	new = f_tok_new(str);
	if (new == NULL)
		return (-1);
	if (*p_head == NULL)
		*p_head = new;
	else
	{
		last = f_tok_last(*p_head);
		last->next = new;
		new->prev = last;
	}
	return (0);
}
