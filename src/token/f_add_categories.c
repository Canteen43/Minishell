/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_categories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:33:23 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/24 11:12:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*Adds categories to tokens*/
void	f_add_categories(t_main *main)
{
	t_tok	*current;

	current = main->tok_head;
	while (current)
	{
		if (f_strscmp(current->str, 5, ">", ">>", "<", "<<", "|"))
			current->type = OPERATOR;
		else if (current->str[0] == '\'')
			current->type = SQUOTE;
		else if (current->str[0] == '\"')
			current->type = DQUOTE;
		else if (current->str[0] == ' ')
			current->type = WHITE;
		else
			current->type = WORD;
		current = current->next;
	}
}
