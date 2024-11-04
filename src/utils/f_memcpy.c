/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:19:19 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/04 08:19:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*start;

	if (!dest || !src)
		return (NULL);
	start = dest;
	while (n-- > 0)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (start);
}
