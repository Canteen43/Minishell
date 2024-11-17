/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:50 by glevin            #+#    #+#             */
/*   Updated: 2024/11/17 17:18:56 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
This function determines the index of a new line character within str,
if there is one. If not, it will return -1.
*/
int	ft_istrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (unsigned char)c)
	{
		if (!str[i++])
			return (-1);
	}
	return (i);
}

/*
This function adds the new buffer from the latest read to the end of the stash.
*/
void	add_to_stash(char **stash, char *buf)
{
	char	*tmp_stash;

	tmp_stash = ft_strjoin(*stash, buf);
	if (tmp_stash == NULL)
	{
		free(buf);
		free(*stash);
		*stash = NULL;
	}
	else
	{
		free(*stash);
		*stash = tmp_stash;
	}
}

/*
This one checks the stash for a new line character. If end of line location
(eol_loc) is not negative, extract that new line and create a new stack
with this line removed.
*/
char	*check_new_line(char **stash)
{
	int		eol_loc;
	char	*next_line;
	char	*tmp_stash;

	eol_loc = ft_istrchr(*stash, '\n');
	if (eol_loc >= 0)
	{
		next_line = ft_substr(*stash, 0, eol_loc + 1);
		tmp_stash = ft_strdup(*stash + eol_loc + 1);
		if (tmp_stash == NULL)
		{
			free(*stash);
			return (NULL);
		}
		free(*stash);
		*stash = tmp_stash;
		return (next_line);
	}
	return (NULL);
}

/*
This one reads the file and saves them to buf. buff_size determines how
many bytes are read from the file on a given call. This function will
continue reading the file in buff_size size chunks, as the end of the
file hasn't been reached (byte_cnt ==0) and there is no new line character
in stash. If the end of the file is reached AND there is no new line in
stash, return stash and free it.
*/
char	*read_file(int fd, char **stash, int buff_size)
{
	char	*buf;
	int		byte_cnt;
	char	*next_line;

	byte_cnt = 1;
	buf = (char *)malloc((buff_size + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	next_line = check_new_line(stash);
	while (!next_line && byte_cnt != 0)
	{
		byte_cnt = read(fd, buf, buff_size);
		buf[byte_cnt] = '\0';
		add_to_stash(stash, buf);
		next_line = check_new_line(stash);
	}
	free(buf);
	if (byte_cnt == 0)
	{
		next_line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (next_line);
}

/*
This one is initializing the static char *stash, in order to have access to
this pointer across multiple function calls. We are checking if the file
descriptor (FD) and buff_size are valid, or if the file is corrupted.
If all looks kosher, we start reading the file into buffer and begin
looking for new lines.
*/

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*stash;
	int			buff_size;

	buff_size = 10;
	if (stash == NULL)
	{
		stash = (char *)malloc(1);
		if (stash == NULL)
			return (NULL);
		stash[0] = '\0';
	}
	if (fd < 0 || buff_size <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	next_line = read_file(fd, &stash, buff_size);
	free(stash);
	stash = NULL;
	if (f_strlen(next_line) != 0)
		return (next_line);
	free(next_line);
	return (NULL);
}
