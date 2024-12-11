/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:22:43 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/11 13:43:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Takes a token. Returns true if tok->str is builtin and false if not.*/
bool	f_is_builtin(t_tok *tok)
{
	if (tok->str == NULL)
		return (false);
	if (f_strcmp(tok->str, "echo") == 0)
		return (true);
	else if (f_strcmp(tok->str, "pwd") == 0)
		return (true);
	else if (f_strcmp(tok->str, "exit") == 0)
		return (true);
	else if (f_strcmp(tok->str, "env") == 0)
		return (true);
	else if (f_strcmp(tok->str, "cd") == 0)
		return (true);
	else if (f_strcmp(tok->str, "unset") == 0)
		return (true);
	else if (f_strcmp(tok->str, "export") == 0)
		return (true);
	else
		return (false);
}
