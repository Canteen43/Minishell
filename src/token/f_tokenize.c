/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/21 08:24:22 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.*/
void	f_tokenize(t_main *main)
{
	f_create_tokens(main);
	if (f_tok_check_syntax(main))
	{
		printf("Syntax error near unexpected token '%s'\n",
			f_tok_check_syntax(main)->str);
	}
	f_unite_double_ops(main);
	f_add_categories(main);
	f_expand_variables(main);
	f_print_tokens(main);
}
