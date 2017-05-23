/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 02:36:47 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/01 22:50:29 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	int		dstlen;
	int		srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	n = (int)size - dstlen - 1;
	if (n >= 0)
	{
		dst = ft_strncat(dst, src, n);
		if (size < ft_strlen(dst))
			return (size);
		else
			return (dstlen + srclen);
	}
	else
		return (srclen + size);
}
