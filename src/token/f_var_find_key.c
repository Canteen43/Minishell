/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_find_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:25:48 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 09:19:39 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Takes start and end of a environment variable name as ptr to char. Returns
value of corresponding str as pointer.*/
// TODO: Replace return ("0") with actual exit status
char	*f_var_find_key(t_main *main, char *start, char *end)
{
	char	*var_string;
	t_env	*node;

	if (*start == '?')
		return ("0");
	var_string = malloc(end - start + 2);
	if (!var_string)
		exit(1);
	f_strncpy(var_string, start, end - start + 1);
	var_string[end - start + 1] = '\0';
	node = f_env_find_key(main->env_head, var_string);
	free(var_string);
	if (!node)
		return (NULL);
	return (node->value);
}
