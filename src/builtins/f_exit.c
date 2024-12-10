/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:28 by glevin            #+#    #+#             */
/*   Updated: 2024/12/10 10:45:37 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static Functions:
static int	sf_is_acceptable(char *str);

void	f_exit(t_main *main, t_tok *tok)
{
	int	ecode;

	write (STDERR_FILENO, "exit\n", 5);
	if (!tok || tok->args[1] == NULL)
		f_free_and_exit(main, NULL, main->exit_status);
	if (!sf_is_acceptable(tok->args[1]))
	{
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, tok->args[1], f_strlen(tok->args[1]));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
		f_free_and_exit(main, NULL, 2);
	}
	ecode = f_atoi(tok->args[1]);
	if (f_array_length(tok->args) > 2)
	{
		write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
		main->exit_status = 1;
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
