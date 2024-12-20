/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tok_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:44:04 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 15:28:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*f_tok_last(t_tok *tok)
{
	if (tok == NULL)
		return (NULL);
	while (tok->next != NULL)
		tok = tok->next;
	return (tok);
}
