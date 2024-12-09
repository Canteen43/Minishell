/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/09 18:00:55 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sf_is_acceptable(char *str);

void	f_exit(t_main *main, t_tok *tok)
{
	int	ecode;

	write (STDERR_FILENO, "exit", 4); 
	if (!sf_is_acceptable(tok->args[1]))
	{
		write(STDERR_FILENO, "minishell: exit: bla: numeric argument required", 47);
		f_free_and_exit(main, NULL, 2);
	}
	ecode = f_atoi(tok->args[1]);
	if (f_array_length(tok->args) > 2)
	{
		write(STDERR_FILENO, "bash: exit: too many arguments", 30);
		return ;
	}
	f_free_and_exit(main, NULL, ecode);
}

static int	sf_is_acceptable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-'
				|| str[i] == '"'))
			return (0);
		i++;
	}
	return (1);
}
