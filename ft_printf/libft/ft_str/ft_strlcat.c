/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:30:21 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:10:10 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	t_uint		i;
	t_uint		j;

	if (!dst || !src)
		return (0);
	i = MAX_UINT;
	while (dst[++i] && size)
		size--;
	if (!size)
		return (i + ft_strlen(src));
	len = i;
	j = MAX_UINT;
	while (src[++j])
		if (size > 1)
		{
			dst[i++] = src[j];
			--size;
		}
	dst[i] = '\0';
	return (len + j);
}
