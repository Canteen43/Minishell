/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/21 13:59:17 by glevin           ###   ########.fr       */
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
	// TODO: Remove this line
	f_print_tokens(main);
}
