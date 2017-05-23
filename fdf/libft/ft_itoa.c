/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 07:15:40 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/21 10:27:53 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbdigits(int n)
{
	int		nbdigits;

	nbdigits = 1;
	if (n >= 0)
	{
		while (n > 9)
		{
			nbdigits++;
			n /= 10;
		}
	}
	else
	{
		nbdigits++;
		while (n < -9)
		{
			nbdigits++;
			n /= 10;
		}
	}
	return (nbdigits);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		nbdigits;

	nbdigits = ft_getnbdigits(n);
	if (!(result = ft_strnew(nbdigits)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n < 0)
		while (--nbdigits > 0)
		{
			result[nbdigits] = (n % 10) * -1 + 48;
			n /= 10;
		}
	else
	{
		while (--nbdigits > -1)
		{
			result[nbdigits] = (n % 10) + 48;
			n /= 10;
		}
	}
	return (result);
}
