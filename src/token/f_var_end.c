/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:30:21 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/23 12:30:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Expects a pointer to the first char after the '$' sign. Returns a pointer to
the last char that is part of the variable*/
char	*f_var_end(char *str)
{
	if (!f_is_alpha(*str) && *str != '_')
		return (str);
	while (f_is_alpha(*str) || *str == '_' || f_is_dig(*str))
		str++;
	return (str - 1);
}
