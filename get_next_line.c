/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:02 by luisfern          #+#    #+#             */
/*   Updated: 2022/05/03 12:49:56 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*fix_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (stash[i])
	{
		temp[j] = stash[i];
		j++;
		i++;
	}
	free(stash);
	return (temp);
}

static char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_read(int fd, char *stash)
{
	int		bytes_read;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	stash = save_read(fd, stash);
	line = get_line(stash);
	stash = fix_stash(stash);
	printf("the stash is - %s\n\n", stash);
	return (line);
}
