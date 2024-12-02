/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_remove_one_universal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:13:13 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/02 10:37:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Deletes one token regardless of its position in the list*/
void	f_tok_remove_one_universal(t_main *main, t_tok *tok)
{
	if (!tok->prev)
		main->tok_head = tok->next;
	if (tok->prev)
		tok->prev->next = tok->next;
	if (tok->next)
		tok->next->prev = tok->prev;
}
