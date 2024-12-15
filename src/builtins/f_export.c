/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/15 18:46:40 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static bool	sf_is_valid_key(char *key);
static void	sf_write_invalid_key(t_main *main, char *key);
static void	sf_update_or_add_key(t_main *main, char *str, bool *invalid_key);

void	f_export(t_main *main, t_tok *tok)
{
	char	**args;
	bool	invalid_key;

	invalid_key = false;
	args = tok->args + 1;
	if (!*args)
	{
		f_env(main);
		return ;
	}
	while (*args)
	{
		sf_update_or_add_key(main, *args, &invalid_key);
		args++;
	}
	if (!invalid_key)
		main->exit_status = 0;
}

static bool	sf_is_valid_key(char *key)
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

static void	sf_write_invalid_key(t_main *main, char *key)
{
	write(STDERR_FILENO, "minishell: export: ", 19);
	if (key)
		write(STDERR_FILENO, key, f_strlen(key));
	write(STDERR_FILENO, ": not a valid identifier\n", 25);
	main->exit_status = 1;
}

static void	sf_update_or_add_key(t_main *main, char *str, bool *invalid_key)
{
	char	*key;
	char	*value;

	key = f_env_strtokey(main, str);
	if (!sf_is_valid_key(key))
	{
		sf_write_invalid_key(main, key);
		*invalid_key = true;
		return ;
	}
	value = f_env_strtovalue(main, str);
	if (f_env_find_key(main->env_head, key))
		f_env_find_key(main->env_head, key)->value = value;
	else
		f_env_add_back(main, key, value);
}
