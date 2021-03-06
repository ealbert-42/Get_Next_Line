/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:29:55 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/11 16:32:47 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findnl(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\n')
		;
	if (str[i] == '\0')
		return (-1);
	return (i);
}
