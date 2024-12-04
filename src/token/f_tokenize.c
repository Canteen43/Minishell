/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 17:45:53 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.*/
// Add f_print_tokens(main); at any point to see what the tokens look like
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
	f_resolve_quotes(main);
	f_join_tokens(main);
	f_delete_white_toks(main);
	f_toks_to_cmds_n_args(main);
	f_add_redirs_to_cmds(main);
	f_delete_pipes(main);
	f_print_tokens(main);
}
