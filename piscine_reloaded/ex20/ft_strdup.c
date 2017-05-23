/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:06:49 by pravoire          #+#    #+#             */
/*   Updated: 2016/11/07 22:32:32 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dst, char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dst[index] = src[index];
	dst[index] = 0;
	return (dst);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*s2;
	int		length;

	length = ft_strlen(src);
	s2 = (char *)malloc(sizeof(*s2) * (length + 1));
	if (s2)
		ft_strcpy(s2, src);
	return (s2);
}
