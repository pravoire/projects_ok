/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:19:26 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:10:52 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		len_s1;
	size_t		len_s2;

	if (n > (len_s1 = ft_strlen(s1)))
		n = len_s1 + 1;
	if (n > (len_s2 = ft_strlen(s2)))
		n = len_s2 + 1;
	return (ft_memcmp((void *)s1, (void *)s2, n));
}
