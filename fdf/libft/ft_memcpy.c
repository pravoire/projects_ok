/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 05:43:43 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/17 22:42:47 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*temp_dst;
	char	*temp_src;

	index = -1;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (++index < n)
		temp_dst[index] = temp_src[index];
	return (dst);
}
