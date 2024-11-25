/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unite_double_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:06:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:31:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Unites double operators into one token*/
void	f_unite_double_ops(t_main *main)
{
	t_tok	*current;

	current = main->tok_head;
	while (current->next)
	{
		if (f_strscmp(current->str, 2, "<", ">") && strcmp(current->str,
				current->next->str) == 0)
		{
			f_tok_remove_one(current->next);
			current->str = f_strjoin(main, current->str, current->str);
		}
		current = current->next;
	}
}
