/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 17:10:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sf_is_acceptable(char *str);

void	f_exit(t_main *main, t_tok *tok)
{
	int	ecode;

	if (!sf_is_acceptable(tok->args[1]))
	{
		printf("numeric argument required");
		exit(2);
	}
	ecode = f_atoi(tok->args[1]);
	f_gc_clean(main);
	if (f_array_length(tok->args) > 2)
	{
		perror("too many arguments");
		exit(1);
	}
	exit(ecode);
}

static int	sf_is_acceptable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || 
		      str[i] == '+' || 
		      str[i] == '-' || 
		      str[i] == '"'))
			return (0);
		i++;
	}
	return (1);
}
