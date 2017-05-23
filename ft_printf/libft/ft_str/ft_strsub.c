/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:50:04 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:11:42 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char		*dst;
	t_uint		i;

	i = MAX_UINT;
	if (!s1)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		dst[i] = s1[start + i];
	dst[len] = '\0';
	return (dst);
}
