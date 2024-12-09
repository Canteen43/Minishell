/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_do_expansions_in_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:24:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/09 10:51:46 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_do_expansions_in_str(t_main *main, char **p_str)
{
	char	*start;
	char	*end;
	char	*value;

	while (f_expandable_dollar_sign(*p_str))
	{
		start = f_expandable_dollar_sign(*p_str) + 1;
		end = f_var_end(start);
		value = f_var_find_key(main, start, end);
		*p_str = f_var_new_string(main, *p_str, value, end);
	}
}
