/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:50:39 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/07 15:16:59 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static char	*sf_type_as_str(int type);
static void	sf_print_redirs(t_tok *redir_head);

/*Debug function to print the tokens*/
void	f_print_tokens(t_main *main)
{
	t_tok	*current;
	int		i;
	char	*type;

	printf("Printing token list...\n");
	current = main->tok_head;
	while (current)
	{
		i = 0;
		printf("==========\n");
		type = sf_type_as_str(current->type);
		printf("Type: %s\n", type);
		printf("String: \"%s\"\n", current->str);
		while (current->args && current->args[i])
			printf("Arg: \"%s\"\n", current->args[i++]);
		sf_print_redirs(current->redir_head);
		printf("==========\n");
		current = current->next;
	}
}

static void	sf_print_redirs(t_tok *redir_head)
{
	t_tok	*current;
	char	*type;
	int		i;

	current = redir_head;
	if (!current)
	{
		printf("No redirections.\n");
		return ;
	}
	printf("Redirections:\n");
	while (current)
	{
		i = 0;
		printf("\t----------\n");
		type = sf_type_as_str(current->type);
		printf("\tType: %s\n", type);
		printf("\tString: \"%s\"\n", current->str);
		while (current->args && current->args[i])
			printf("\tArg: \"%s\"\n", current->args[i++]);
		current = current->next;
		printf("\t----------\n");
	}
}

static char	*sf_type_as_str(int type)
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
