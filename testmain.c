/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:27:54 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/03 08:44:55 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = getcwd(NULL, 0);
	printf("getcwd return: %s\n", s1);
	s2 = getenv("PWD");
	printf("get_current_dir_name return: %s\n", s2);
	chdir("/home");
	s1 = getcwd(NULL, 0);
	printf("getcwd return: %s\n", s1);
	s2 = getenv("PWD");
	printf("get_current_dir_name return: %s\n", s2);
}
