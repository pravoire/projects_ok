/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 05:38:07 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/05 06:19:00 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrev(const char *src)
{
	char			*dst;
	int				i;
	int				j;

	j = ft_strlen(src);
	i = 0;
	if (!src || !(dst = ft_strnew(j)))
		return (NULL);
	dst[j--] = '\0';
	while (j >= 0)
		dst[i++] = src[j--];
	return (dst);
}
