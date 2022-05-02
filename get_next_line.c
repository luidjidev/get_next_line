/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:02 by luisfern          #+#    #+#             */
/*   Updated: 2022/04/27 15:12:26 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
	{
		s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3[i] = 0;
	return (s3);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	int			i;
	int			bytes_read;
	char		buf[BUFFER_SIZE + 1];
	char		*saved;
	static char	*line;

	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n') >= 0)
		{
			saved = malloc((i + 1) * sizeof(char));
			while (*buf != '\n')
			{
				*saved = *buf;
				*saved++;
				*line++;
			}
			break ;
		}
	}
	return (saved);
}
