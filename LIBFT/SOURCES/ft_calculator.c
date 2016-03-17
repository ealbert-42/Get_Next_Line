/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:08:28 by ealbert           #+#    #+#             */
/*   Updated: 2015/12/03 15:13:53 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calculator(int nb1, char c, int nb2)
{
	int		nbpw;

	nbpw = nb1;
	if (c == '+')
		return (nb1 + nb2);
	if (c == '-')
		return (nb1 - nb2);
	if (c == '*')
		return (nb1 * nb2);
	if (c == '/')
		return (nb1 / nb2);
	if (c == '%')
		return (nb1 % nb2);
	if (c == '^')
	{
		while (nb2-- > 1)
		{
			nb1 *= nbpw;
		}
		return (nb1);
	}
	return (0);
}
