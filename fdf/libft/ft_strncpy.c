/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 01:35:54 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/17 22:46:23 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	length;
	size_t	index;

	length = ft_strlen(src);
	index = -1;
	if (length < n)
	{
		while (++index < length)
			dst[index] = src[index];
		while (index < n)
			dst[index++] = 0;
	}
	else
		while (++index < n)
			dst[index] = src[index];
	return (dst);
}
