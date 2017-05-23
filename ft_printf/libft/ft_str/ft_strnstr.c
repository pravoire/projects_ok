/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:09:56 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:11:19 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	if (!(len = ft_strlen(s2)))
		return ((char *)s1);
	while (len <= (n - ++i) && s1[i])
		if (!ft_strncmp(&s1[i], s2, len))
			return ((char *)&s1[i]);
	return (NULL);
}
