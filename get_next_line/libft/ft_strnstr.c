/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 05:27:04 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/10 02:42:04 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	offset;

	offset = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[offset] && (offset < n))
	{
		index = 0;
		while ((s1[index + offset] == s2[index]) && s2[index] &&
				((index + offset) < n))
			index++;
		if (s2[index] == 0)
			return ((char *)&s1[offset]);
		offset++;
	}
	return (NULL);
}
