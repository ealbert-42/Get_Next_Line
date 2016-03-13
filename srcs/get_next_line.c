/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:16:07 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/13 19:45:47 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char		*get_copy(char **str)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strccpy(tmp, *str, '\n');
	*str = ft_strcdel(*str, '\n');
	return (tmp);
}



int			get_next_line(int fd, char **line)
{
	static char	*array[MAX_FD];
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 3 || fd > MAX_FD || !(array[fd - 3] = malloc(BUFF_SIZE + 1)))
		return (-1);
	ft_bzero(array[fd - 3], BUFF_SIZE + 1);
	ret = 1;
	while (ret != 0)
	{
		if ((ret = read(fd, &buf, BUFF_SIZE)) == -1)
			return (ret);
		buf[ret] = '\0';
		printf("Your buffer contains : '%s'\n", buf);
	//	array[fd] = ft_strcat(array[fd], buf);
	//	array[fd] = ft_strrealloc(array[fd], BUFF_SIZE);
	//	if (ft_findnl(array[fd]) != -1)
	//		break ;
	}
	/**line = get_copy(&array[fd]);*/
	if (ret == 0)
		free(array[fd]);
	return (ret != 0 ? 1 : 0);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl;

	gnl = 2;
	fd = open(argv[1], O_RDONLY);
	printf("Your new file descriptor is '%d'.\n", fd);
	gnl = get_next_line(fd, &line);
	printf("Your gnl returned %d and line is equal to %s", gnl, line);
	return (0);
}
