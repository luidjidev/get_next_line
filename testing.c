/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:40:56 by luisfern          #+#    #+#             */
/*   Updated: 2022/05/02 17:38:16 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("42.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error\n");
		return (0);
	}
	printf("%s", get_next_line(fd));
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return (0);
	}
	return (0);
}
