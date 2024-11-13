/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/13 09:15:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Creates a linked list of tokens from the string provided.
WIP: For now, it prints the tokens. Later it will create the linked list.*/
void	f_tokenize(t_main *main)
{
	str = main->user_input;
	while (str[i])
	{
		while (str[i] == ' ')
		{
			if (last token is not white)
				create token;
			i++;
		}
		if non-whitespace
			get_end;
		malloc token and substr;
		i = end + 1;
	}
}
