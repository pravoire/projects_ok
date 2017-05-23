/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:21:25 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:06:43 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*cp;

	cp = dst;
	while (n--)
	{
		*(t_uchar *)dst = *(t_uchar*)src;
		dst++;
		src++;
	}
	return (cp);
}
