/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:21:44 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/17 17:52:46 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char			*joining(char *s1, char *s2)
{
	char			*new;

	if (!s1)
	{
		if (!(new = malloc(ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(new, s2);
		return (new);
	}
	else
	{
		if (!(new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
		return (new);
	}
}

static char			*allocation(char *str)
{
	int				i;
	int				j;

	i = 1;
	while (str[i - 1] != '\n' && str[i - 1] != '\0')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	if (j - i == 0)
		return (NULL);
	return (ft_strsub(str, i, j - i));
}

static char			*cutting(char *str)
{
	int				i;
	char			*tmp;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	tmp = malloc(i + 1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*array[MAX_FD];
	unsigned int	ret;
	char			buf[BUFF_SIZE + 1];

	if (fd < 3 || fd > MAX_FD || !(*line = malloc(1)))
		return (-1);
	ret = BUFF_SIZE;
	if (!array[fd - 3])
	{
		while (ret == BUFF_SIZE)
		{
			if ((ret = read(fd, &buf, BUFF_SIZE)) < 1)
				return (ret);
			buf[ret] = '\0';
			array[fd - 3] = joining(array[fd - 3], buf);
		}
	}
	*line = cutting(array[fd - 3]);
	array[fd - 3] = allocation(array[fd - 3]);
	if (*line)
		return (1);
	return (0);
}
