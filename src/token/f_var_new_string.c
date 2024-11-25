/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_new_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:51:43 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/25 13:32:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Expects a string that contains a "$" (oldstr) and returns a copy of that
string but everything from "$" to end is replaced with valstr (which corresponds
to the value of the env_variable.*/
char	*f_var_new_string(t_main *main, char *oldstr, char *valstr, char *end)
{
	char		*newstr;
	size_t		bytes_before;
	size_t		len_total;
	size_t		len_valstr;

	(void)main;
	bytes_before = f_strchr(oldstr, '$') - oldstr;
	if (!valstr)
		valstr = "";
	len_valstr = f_strlen(valstr);
	len_total = bytes_before + len_valstr + strlen(end + 1);
	newstr = f_gc_malloc(main, sizeof(char) * (len_total + 1));
	if (!newstr)
		f_free_and_exit(main, MALLOCFAIL, 1);
	f_strncpy(newstr, oldstr, bytes_before);
	f_strcpy(newstr + bytes_before, valstr);
	f_strcpy(newstr + bytes_before + len_valstr, end + 1);
	newstr[len_total] = '\0';
	return (newstr);
}
