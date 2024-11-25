/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_arg_to_tok.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:40:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/24 14:50:02 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static Functions
static size_t	sf_get_len_args(char **args);

/*Adds a str to the char **args of a given token.*/
void	f_add_arg_to_tok(t_main *main, char *arg, t_tok *tok)
{
	size_t	len_args_new;
	char	**args_new;
	int		i;

	len_args_new = sf_get_len_args(tok->args) + 1;
	args_new = f_gc_malloc(main, len_args_new + 1);
	i = 0;
	while (len_args_new != 1 && tok->args[i])
	{
		args_new[i] = tok->args[i];
		i++;
	}
	args_new[i] = arg;
	args_new[i + 1] = NULL;
	tok->args = args_new;
}

static size_t	sf_get_len_args(char **args)
{
	size_t	len;

	len = 0;
	if (!args)
		return (len);
	while (*args)
	{
		len++;
		args++;
	}
	return (len);
}
