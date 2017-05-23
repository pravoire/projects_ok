/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:04:22 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:10:36 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	t_uint		i;
	size_t		len;
	char		*dst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = MAX_UINT;
	while (s[++i])
		dst[i] = f(s[i]);
	dst[len] = '\0';
	return (dst);
}
