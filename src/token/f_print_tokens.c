/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:50:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/23 12:48:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*f_type_as_str(int type)
{
	if (type == NONE)
		return ("NONE");
	if (type == WHITE)
		return ("WHITE");
	if (type == WORD)
		return ("WORD");
	if (type == SQUOTE)
		return ("SQUOTE");
	if (type == DQUOTE)
		return ("DQUOTE");
	if (type == OPERATOR)
		return ("OPERATOR");
	return ("UNKNOWN");
}

/*Debug function to print the tokens*/
void	f_print_tokens(t_main *main)
{
	t_tok	*current;
	int		i;
	char	*type;

	current = main->tok_head;
	i = 0;
	while (current)
	{
		type = f_type_as_str(current->type);
		printf("Token %d:\nType: %s\nString: %s\n\n", i, type,
			current->str);
		current = current->next;
		i++;
	}
}
