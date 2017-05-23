/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 02:23:48 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:09:25 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strcpy(char *dst, const char *src)
{
	t_uint		i;

	if (!dst || !src)
		return (NULL);
	i = MAX_UINT;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
