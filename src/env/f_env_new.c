/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_env_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:45:18 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 14:00:32 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*f_env_new(t_main *main, char *key, char *value)
{
	t_env	*new;

	new = (t_env *)f_gc_malloc(main, sizeof(t_env));
	if (!new)
		f_free_and_exit(main, MALLOCFAIL, 1);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
