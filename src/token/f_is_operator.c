/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:59:18 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/08 15:23:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns true if tok->type is a redirection (incl. heredoc)*/
bool	f_is_operator(t_tok *tok)
{
	if (!tok)
		return (false);
	if (tok->type == REDIR_IN
		|| tok->type == REDIR_HEREDOC
		|| tok->type == REDIR_OUT
		|| tok->type == REDIR_OUT_APP
		|| tok->type == PIPE)
		return (true);
	return (false);
}
