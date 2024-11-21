/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_new_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:51:43 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/21 08:18:18 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*f_var_new_string(t_main main, char *oldstr; char *valstr, char *end)
{
	char		*newstr;
	size_t		bytes_before;
	size_t		len_total;
	size_t		len_valstr;

	bytes_before = f_strchr(oldstr, '$') - oldstr;
	if (!valstr)
		valstr = "";
	len_valstr = f_strlen(valstr);
	len_total = bytes_before + len_valstr + strlen(end + 1);
	newstr = malloc(sizeof(char) * (len_total + 1));
	//TODO Protect malloc
	f_strncpy(new, oldstr, bytes_before);
	f_strcpy(new + bytes_before, value);
	f_strcpy(new + bytes_before + len_valstr, end + 1);
	newstr[len_total] = '\0';
	return (newstr);
}
