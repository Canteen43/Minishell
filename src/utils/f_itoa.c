/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:58:17 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/02 12:16:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions:
static int	nbr_digs(int n);
static void	fill_array(char *ptr, int n);

char	*ft_itoa(t_main *main, int n)
{
	int		digs;
	size_t	size;
	char	*ptr;

	digs = nbr_digs(n);
	size = digs + 1;
	if (n < 0)
		size += 1;
	ptr = f_gc_malloc(main, size);
	if (!ptr)
		f_free_and_exit(main, MALLOCFAIL, 1);
	if (n < 0)
		*ptr++ = '-';
	fill_array(ptr, n);
	ptr[digs] = '\0';
	if (n < 0)
		ptr--;
	return (ptr);
}

static int	nbr_digs(int n)
{
	int	i;

	if (n > 0)
		n *= -1;
	i = 1;
	while (n <= -10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_array(char *ptr, int n)
{
	if (n > 0)
		n *= -1;
	if (n <= -10)
		fill_array(ptr, n / 10);
	ptr[nbr_digs(n) -1] = '0' + (n % 10) * -1;
}
