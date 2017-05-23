/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 04:37:57 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/01 23:08:56 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = -1;
	if (s)
	{
		if ((char)c == '\0')
			return ((char *)(s + ft_strlen(s)));
		while (s[++index])
			if (s[index] == (char)c)
				return ((char *)(s + index));
	}
	return (NULL);
}
