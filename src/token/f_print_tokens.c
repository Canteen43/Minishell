/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:50:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/17 10:43:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Debug function to print the tokens*/
void	f_print_tokens(t_main *main)
{
	t_tok	*current;
	int		i;

	current = main->tok_head;
	i = 0;
	while (current)
	{
		printf("Token %d:\nType: %d\nString: %s\n\n", i, current->type,
			current->str);
		current = current->next;
		i++;
	}
}
