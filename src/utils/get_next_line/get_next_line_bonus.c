/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:38:32 by llepesqu          #+#    #+#             */
/*   Updated: 2026/01/19 10:51:19 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	update_stash(char **stash, char *buf, int size)
{
	char	*tmp;

	if (!*stash)
		*stash = ft_strndup(buf, size);
	else
	{
		tmp = ft_strjoin(*stash, buf);
		free(*stash);
		*stash = tmp;
	}
}

char	*extract_line(char **stash, int index)
{
	char	*line;
	char	*tmp;

	if (index == -1)
	{
		line = ft_strndup(*stash, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	else
	{
		line = ft_strndup(*stash, index + 1);
		if (*stash && !line)
			return (free(*stash), *stash = NULL, NULL);
		if ((*stash)[index + 1] != '\0')
			tmp = ft_strndup(*stash + index + 1, ft_strlen(*stash) - index - 1);
		else
			tmp = NULL;
		free(*stash);
		*stash = tmp;
	}
	return (line);
}

int	read_until_newline(int fd, char **stash, char *buf)
{
	int	index;
	int	size;

	size = 1;
	index = ft_index_of_char(*stash, '\n');
	while (index == -1 && size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(*stash);
			*stash = NULL;
			return (-1);
		}
		buf[size] = '\0';
		update_stash(stash, buf, size);
		index = ft_index_of_char(*stash, '\n');
	}
	return (index);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*buf;
	int			index;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	index = read_until_newline(fd, stash + fd, buf);
	free(buf);
	return (extract_line(stash + fd, index));
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	char *line;
// 	int fd = open("multiple_nl.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// }
