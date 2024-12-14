/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/14 13:53:39 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static bool	sf_valid_key(char *key);
static void	write_invalid_key(t_main *main, char *key);

void	f_export(t_main *main, t_tok *tok)
{
	char	*key;
	char	*value;
	char	**args;

	args = tok->args + 1;
	if (!*args)
	{
		f_env(main);
		return ;
	}
	while (*args)
	{
		key = f_env_strtokey(main, *args);
		if (!sf_valid_key(key))
		{
			write_invalid_key(main, key);
			return ;
		}
		value = f_env_strtovalue(main, *args);
		if (f_env_find_key(main->env_head, key))
			f_env_find_key(main->env_head, key)->value = value;
		else
			f_env_add_back(main, key, value);
		args++;
	}
}

static bool	sf_valid_key(char *key)
{
	if (!key)
		return (false);
	if (*key != '_' && !f_is_alpha(*key))
		return (false);
	while (*key)
	{
		if (*key != '_' && !f_is_alpha(*key) && !f_is_dig(*key))
			return (false);
		key++;
	}
	return (true);
}

static void	write_invalid_key(t_main *main, char *key)
{
	write(STDERR_FILENO, "minishell: export: ", 19);
	if (key)
		write(STDERR_FILENO, key, f_strlen(key));
	write(STDERR_FILENO, ": not a valid identifier\n", 25);
	main->exit_status = 1;
}
