/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_categories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:33:23 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 12:53:36 by kweihman         ###   ########.fr       */
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
		if (f_strcmp(current->str, "|") == 0)
			current->type = PIPE;
		else if (f_strcmp(current->str, ">") == 0)
			current->type = REDIR_OUT;
		else if (f_strcmp(current->str, ">>") == 0)
			current->type = REDIR_OUT_APP;
		else if (f_strcmp(current->str, "<") == 0)
			current->type = REDIR_IN;
		else if (f_strcmp(current->str, "<<") == 0)
			current->type = REDIR_HEREDOC;
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
