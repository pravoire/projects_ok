/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:13:00 by pravoire          #+#    #+#             */
/*   Updated: 2016/11/07 21:44:20 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*res;
	int	range;

	if (min >= max)
		return (NULL);
	range = max - min;
	res = (int *)malloc(sizeof(*res) * range);
	while (--range >= 0)
		res[range] = --max;
	return (res);
}
