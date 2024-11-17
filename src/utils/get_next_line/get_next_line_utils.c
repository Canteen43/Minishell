/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:54 by glevin            #+#    #+#             */
/*   Updated: 2024/11/17 17:12:44 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
The	function copies n characters from memory area src to memory area dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
The function strdup() duplicates a string. It returns a pointer to
null-terminated byte string.
*/
char	*ft_strdup(const char *string)
{
	char	*str2;
	size_t	string_len;

	string_len = f_strlen(string) + 1;
	str2 = malloc(string_len * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str2, string, string_len));
}

/*
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	size_t			i;

	s_len = f_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = f_strlen(s1);
	s2_len = f_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	s3 = ft_memcpy(s3, s1, s1_len + 1);
	while (s2[i])
	{
		s3[s1_len + i] = s2[i];
		i++;
	}
	s3[s1_len + i] = '\0';
	return (s3);
}
