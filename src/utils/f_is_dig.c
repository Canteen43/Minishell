/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_dig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:45 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 17:03:22 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns true if char c is alphabetical, false if not.*/
bool	f_is_dig(char c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	else
		return (false);
}
