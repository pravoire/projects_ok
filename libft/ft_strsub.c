/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:25:42 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/05 02:34:34 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*result;

	index = -1;
	result = (char *)malloc(sizeof(*result) * len + 1);
	if (result)
	{
		while (++index < len)
			result[index] = s[start + index];
		result[index] = '\0';
	}
	return (result);
}
