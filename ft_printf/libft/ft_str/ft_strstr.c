/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:45:01 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:11:35 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	if (!(len = ft_strlen(s2)))
		return ((char *)s1);
	while (s1[++i])
		if (!ft_strncmp(&s1[i], s2, len))
			return ((char *)&s1[i]);
	return (NULL);
}
