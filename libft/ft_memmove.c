/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 06:21:39 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/01 21:12:54 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst && src)
	{
		temp_dst = (unsigned char *)dst;
		temp_src = (unsigned char *)src;
		if (dst < src)
			ft_memcpy(dst, src, len);
		else
			while (len-- > 0)
				temp_dst[len] = temp_src[len];
	}
	return (dst);
}
