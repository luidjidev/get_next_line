/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:02 by luisfern          #+#    #+#             */
/*   Updated: 2022/05/02 17:38:31 by luisfern         ###   ########.fr       */
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
	return (temp);
}

static char	*get_line(char *stash, char *line)
{
	int	i;

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
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*stash;

	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (NULL);
		}
		ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n') >= 0)
		{
			line = get_line(stash, line);
			stash = fix_stash(stash);
		}
	}
	return (line);
}
