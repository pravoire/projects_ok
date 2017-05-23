/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 03:29:59 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:10:46 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	len = ft_strlen(dst);
	while (n-- && src[++i])
		dst[len++] = src[i];
	dst[len] = '\0';
	return (dst);
}
