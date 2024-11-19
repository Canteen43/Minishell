/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_del_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:13:13 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/17 11:13:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Deletes one token*/
void	f_tok_del_one(t_tok *tok)
{
	if (tok->prev)
		tok->prev->next = tok->next;
	if (tok->next)
		tok->next->prev = tok->prev;
	free(tok->str);
	free(tok);
}
