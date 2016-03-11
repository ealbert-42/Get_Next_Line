/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:00:41 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/11 16:02:59 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* You can change the buffer size and the maximum fd that can be open. */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50
# define MAX_FD 256
# include "libft.h"

int					get_next_line(int fd, char **line);

#endif
