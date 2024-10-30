/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:58:35 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 14:22:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// From Libft
int	ft_strcmp(const char *s1, const char *s2);

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		perror("Too few arguments.");
	if (ft_strcmp(argv[1], "echo") == 0)
		f_echo(argc, argv, envp);
	else
		perror("Command not found.");
	return (0);
}
