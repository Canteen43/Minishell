/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:27:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/17 11:11:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	main(void)
{
	char	*str;
	char	**arr;
	int		i;

	str = "echo hi hi hi hi hi h    ";
	arr = f_split(str, ' ');
	printf("String: %s\n", str);
	printf("Command: %s\n", arr[0]);
	i = 0;
	while (arr[i])
	{
		printf("arr[%d]: %s\n", i, arr[i]);
		i++;
	}
}
