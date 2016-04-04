/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:47:30 by ealbert           #+#    #+#             */
/*   Updated: 2016/04/04 20:50:36 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#define MAX_FD 256
#define BUFF_SIZE 3
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int			find_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
				return (i);
		i++;
	}
	return (-1);
}

int			cut_line(char **array, char **line, int len)
{
	char	*tmp;

	*line = ft_strsub(*array, 0, len);
	tmp = *array;
	*array = ft_strdup(ft_strchr(*array, '\n') + 1);
	ft_strdel(&tmp);
	printf("\narray ===>'%s'\n", *array);
	return (1);
}

int			read_file(int fd, char **array, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;
	int		len;

	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
printf("%d <= ret\n", ret);
printf("array =>'%s'\n", *array);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if ((len = find_nl(*array)) > -1)
			return (cut_line(array, line, len));
		tmp = *array;
		*array = ft_strjoin(*array, buf);
		ft_strdel(&tmp);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*array[MAX_FD];
	int				ret;
	int				len;

	*line = "";
	if (fd < 3 || fd > MAX_FD || BUFF_SIZE <= 0)
		return (-1);
//	if ((len = find_nl(array[fd])) != -1)
//		return (cut_line(&array[fd], line, len));
	if (!array[fd])
		array[fd] = ft_strnew(0);
	if ((ret = read_file(fd, &array[fd], line)) && ret != 2)
		return (ret);
	return (0);
}

int			main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		get;
	int		ok;

	ok = 0;
	get = 1;
	line = ft_strnew(0);
	fd = open(argv[1], O_RDONLY);
	while (get)
	{
		get = get_next_line(fd, &line);
		if (get == -1 || ok == 1)
			break ;
		printf("====>'%s'<====\nget = %d\n", line, get);
	}
	return (0);
}
