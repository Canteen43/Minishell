/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_find_final_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:47:56 by glevin            #+#    #+#             */
/*   Updated: 2024/12/02 10:48:15 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*f_find_final_cmd(t_main *main)
{
	t_tok	*tok;
	t_tok	*final_cmd_tok;

	tok = main->tok_head;
	while (tok)
	{
		if (tok->type == COMMAND)
			final_cmd_tok = tok;
		tok = tok->next;
	}
	return (final_cmd_tok);
}
