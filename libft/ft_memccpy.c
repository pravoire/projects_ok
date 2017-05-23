/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 06:02:23 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/12 06:51:55 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	index = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while ((index < n) && (temp_src[index] != (unsigned char)c))
	{
		temp_dst[index] = temp_src[index];
		index++;
	}
	if (index == n)
		return (NULL);
	else
	{
		temp_dst[index] = temp_src[index];
		return (&temp_dst[index + 1]);
	}
}
