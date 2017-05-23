/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 02:30:30 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:11:00 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	t_uint		i;

	i = MAX_UINT;
	while (++i < n && src[i])
		dst[i] = src[i];
	ft_bzero((void *)&dst[i], n - i);
	return (dst);
}
