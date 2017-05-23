/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 23:33:43 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/14 22:27:15 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*res;

	res = s1;
	while (*res)
		res++;
	if (n > 0)
	{
		while (*s2 && n)
		{
			*(res++) = *(s2++);
			n--;
		}
		*res = '\0';
	}
	return (s1);
}
