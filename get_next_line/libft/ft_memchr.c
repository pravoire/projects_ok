/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 05:49:33 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/17 22:44:20 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*temp_s;

	index = -1;
	temp_s = (unsigned char *)s;
	while (++index < n)
		if (temp_s[index] == (unsigned char)c)
			return (&temp_s[index]);
	return (NULL);
}
