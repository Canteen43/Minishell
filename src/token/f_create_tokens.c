/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:57:17 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:48:59 by kweihman         ###   ########.fr       */
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
	main->tok_head = f_tok_new(main, f_strdup(main, " "));
	while (main->user_input[i])
	{
		while (main->user_input[i] == ' ')
		{
			if (f_strcmp((f_tok_last(main->tok_head))->str, " ") != 0)
				f_tok_add_back(main, f_strdup(main, " "));
			i++;
		}
		end = f_get_token_end(main->user_input, i);
		if (end == -1)
			exit(1);
		new = f_gc_malloc(main, end - i + 1 + 1);
		if (!new)
			f_free_and_exit(main, MALLOCFAIL, 1);
		memcpy(new, main->user_input + i, end - i + 1);
		new[end - i + 1] = '\0';
		f_tok_add_back(main, new);
		i = end + 1;
	}
}
