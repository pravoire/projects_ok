/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:01:16 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/13 21:36:15 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*result;

	index = -1;
	result = (char *)malloc(sizeof(*result) * ft_strlen(s) + 1);
	if (result)
	{
		while (s[++index])
			result[index] = f(s[index]);
		result[index] = 0;
	}
	return (result);
}
