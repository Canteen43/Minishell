/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/13 13:59:57 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.
WIP: For now, it prints the tokens. Later it will create the linked list.*/
void	f_tokenize(t_main *main)
{
	int		i;
	int		end;
	char	*str;
	char	*new;

	i = 0;
	str = main->user_input;
	main->tok_head = f_tok_new(f_strdup(" "));
	while (str[i])
	{
		while (str[i] == ' ')
		{
			if (f_strcmp((f_tok_last(main->tok_head))->str, " ") != 0)
				f_tok_add_back(&main->tok_head, f_strdup(" "));
			i++;
		}
		end = f_get_token_end(str, i);
		if (end == -1)
			exit(1);
		new = malloc(2 + end - i);
		if (!new)
			exit(1);
		memcpy(new, str + i, end - i + 1);
		if (f_tok_add_back(&main->tok_head, new) == -1)
			exit(1);
		i = end + 1;
	}
}
