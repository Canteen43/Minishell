/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_expand_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:37:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 17:04:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_expand_variable(t_main *main)
{
	t_tok	*tok;
	char	*start;

	tok = main->tok_head;
	while (tok)
	{
		while (1)
		{
			start = f_strchr(tok->str, '$') + 1;
			
		}
		tok = tok->next;
	}
}
