/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_var_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:50:38 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 18:57:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Takes start and end of var to replace, as well as current token.*/
void	f_var_replace(t_main *main, char *start, char *end)
{
	int	len;

	len = end - start + 1;
	