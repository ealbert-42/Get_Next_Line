/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:16:07 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/11 18:31:51 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	static char	*array[MAX_FD];
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 3 || fd > MAX_FD)
		return (-1);
	fd -= 3;
	if (!(array[fd] = (char *)malloc(BUFF_SIZE + 1)))
		return (NULL);
	ft_bzero(array[fd], BUFF_SIZE + 1);
	while (ft_findnl(array[fd]) == -1)
	{
		ret = read(fd, &buf, BUFF_SIZE);
		buf[ret] = '\0';
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl;

	gnl = 2;
	fd = open(argv[1], O_RDONLY);
	line = ft_memset((void *)line, 0, 51);
	printf("Your new file descriptor is '%d'.\n", fd);
	while (gnl != 0 && gnl != 1)
	{
		gnl = get_next_line(fd, &line);
	}
	return (0);
}
