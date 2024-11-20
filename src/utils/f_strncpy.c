/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strncpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:05:22 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 19:09:56 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Copies at most n bytes from src to dest.*/
void	f_strncpy(char *dest, char *src, size_t n)
{
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
}
