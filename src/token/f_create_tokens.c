/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:57:17 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/16 10:58:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.*/
void	f_create_tokens(t_main *main)
{
	int		i;
	int		end;
	char	*new;

	i = 0;
	main->tok_head = f_tok_new(f_strdup(" "));
	while (main->user_input[i])
	{
		while (main->user_input[i] == ' ')
		{
			if (f_strcmp((f_tok_last(main->tok_head))->str, " ") != 0)
				f_tok_add_back(&main->tok_head, f_strdup(" "));
			i++;
		}
		end = f_get_token_end(main->user_input, i);
		if (end == -1)
			exit(1);
		new = malloc(2 + end - i);
		if (!new)
			exit(1);
		memcpy(new, main->user_input + i, end - i + 1);
		if (f_tok_add_back(&main->tok_head, new) == -1)
			exit(1);
		i = end + 1;
	}
}
