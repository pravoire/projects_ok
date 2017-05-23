/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 04:42:36 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/01 23:16:49 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[index]);
	while (--index >= 0)
		if (s[index] == (char)c)
			return ((char *)&s[index]);
	return (NULL);
}
