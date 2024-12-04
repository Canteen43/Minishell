/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:50:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 12:56:07 by kweihman         ###   ########.fr       */
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
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIR_HEREDOC)
		return ("REDIR_HEREDOC");
	if (type == REDIR_OUT)
		return ("REDIR_OUT");
	if (type == REDIR_OUT_APP)
		return ("REDIR_OUT_APP");
	if (type == REDIR_IN)
		return ("REDIR_IN");
	if (type == COMMAND)
		return ("COMMAND");
	return ("UNKNOWN");
}

/*Debug function to print the tokens*/
void	f_print_tokens(t_main *main)
{
	t_tok	*current;
	char	*type;

	printf("Token List:\n\n");
	current = main->tok_head;
	while (current)
	{
		type = f_type_as_str(current->type);
		printf("Type: %s\n", type);
		printf("String: \"%s\"\n", current->str);
		while (current->args && *(current->args))
			printf("Arg: \"%s\"\n", *(current->args)++);
		printf("\n");
		current = current->next;
	}
}
