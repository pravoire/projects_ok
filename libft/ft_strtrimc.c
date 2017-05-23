/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 06:43:51 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/05 01:20:17 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	offset;
	size_t	roffset;
	char	*result;

	if (!s)
		return (0);
	offset = 0;
	roffset = ft_strlen(s);
	roffset--;
	while (s[offset] == c)
		offset++;
	while (s[roffset] == c)
		roffset--;
	if (s[offset] == 0)
		result = ft_strdup("");
	else
		result = ft_strsub(s, (unsigned int)offset, (roffset - offset + 1));
	return (result);
}
