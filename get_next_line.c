/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:02 by luisfern          #+#    #+#             */
/*   Updated: 2022/05/13 00:13:54 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fix_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

static char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
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

char	*save_read(int fd, char *stash, int bytes_read)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			free(buff);
			return (stash);
		}
		buff[BUFFER_SIZE] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	bytes_read = 1;
	stash = save_read(fd, stash, bytes_read);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = fix_stash(stash);
	return (line);
}
