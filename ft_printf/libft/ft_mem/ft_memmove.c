/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:06:39 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:06:54 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (dst);
	else if (dst > src)
	{
		dst += len;
		src += len;
		while (len--)
			*(t_uchar *)dst-- = *(t_uchar *)src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
