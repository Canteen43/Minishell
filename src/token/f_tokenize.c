/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/14 10:37:55 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided. Returns 0 if
there were no syntax errors. Returns 1 if input cannot be executed.*/
// Add f_print_tokens(main); at any point to see what the tokens look like
int	f_tokenize(t_main *main)
{
	f_create_tokens(main);
	f_unite_double_ops(main);
	f_add_categories(main);
	if (f_tok_check_syntax(main))
	{
		main->exit_status = 2;
		return (1);
	}
	f_do_expansions_for_toks(main);
	f_resolve_quotes(main);
	f_join_tokens(main);
	f_delete_empty_tokens(main);
	if (f_only_white_tokens(main))
		return (1);
	f_delete_white_toks(main);
	f_toks_to_cmds_n_args(main);
	f_add_redirs_to_cmds(main);
	f_delete_pipes(main);
	return (0);
}
