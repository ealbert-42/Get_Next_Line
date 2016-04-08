/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:54:06 by ealbert           #+#    #+#             */
/*   Updated: 2016/04/04 17:00:12 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, int n)
{
	char	*new;
	int		i;

	if (!(new = malloc(n + 1)))
		return (NULL);
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\n';
	return (new);
}
