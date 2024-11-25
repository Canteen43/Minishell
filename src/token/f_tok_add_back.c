/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:27:10 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:47:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	f_tok_add_back(t_main *main, char *str)
{
	t_tok	*new;
	t_tok	*last;

	new = f_tok_new(main, str);
	if (main->tok_head == NULL)
		main->tok_head = new;
	else
	{
		last = f_tok_last(main->tok_head);
		last->next = new;
		new->prev = last;
	}
	return (0);
}
