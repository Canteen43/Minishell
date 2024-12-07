/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atoi_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:46:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/07 09:48:49 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static functions
static int	sf_lmt_check(int value, char next);

/*Converts a string to an integer. Returns -1 on Error and 0 on Success.
Errors include: non-digit characters, multiple minuses, number outside of INT
limits, and empty strings.
Ignores leading whitespace (' ' and '\t'), accepts one minus.*/
int	f_atoi_mod(char *str, int *num)
{
	int	sign;

	*num = 0;
	sign = 1;
	if (str == NULL)
		return (-1);
	if (*str == '\0')
		return (-1);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9' && sf_lmt_check(*num, *str) == 0)
			*num = *num * 10 + sign * (*str - '0');
		else
			return (-1);
		str++;
	}
	return (0);
}

static int	sf_lmt_check(int value, char next)
{
	if (value > 0)
	{
		if (INT_MAX / value < 10)
			return (-1);
		if (INT_MAX / value > 10)
			return (0);
		if (INT_MAX / value == 10)
			if (INT_MAX % value < next - '0')
				return (-1);
	}
	if (value < -1)
	{
		if (INT_MIN / value < 10)
			return (-1);
		if (INT_MIN / value > 10)
			return (0);
		if (INT_MIN / value == 10)
			if (INT_MIN % value * -1 < next - '0')
				return (-1);
	}
	return (0);
}
