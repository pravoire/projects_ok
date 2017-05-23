/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 04:05:36 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/12 21:14:45 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		index;
	size_t		sign_index;
	long long	result;

	index = 0;
	result = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t' ||
			str[index] == '\v' || str[index] == '\r' || str[index] == '\f')
		index++;
	sign_index = index;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] > 47 && str[index] < 58)
	{
		result = result * 10 + str[index] - 48;
		index++;
		if (result < 0 && str[sign_index] == '-')
			return (0);
		else if (result < 0)
			return (-1);
	}
	if (str[sign_index] == '-')
		result *= -1;
	return ((int)result);
}
