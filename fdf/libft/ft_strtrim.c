/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:39:51 by pravoire          #+#    #+#             */
/*   Updated: 2014/12/01 21:26:58 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	offset;
	size_t	roffset;
	char	*result;

	if (!s)
		return (0);
	offset = 0;
	roffset = ft_strlen(s);
	roffset--;
	while (s[offset] == ' ' || s[offset] == '\t' || s[offset] == '\n')
		offset++;
	while (s[roffset] == ' ' || s[roffset] == '\t' || s[roffset] == '\n')
		roffset--;
	if (s[offset] == 0)
		result = ft_strdup("");
	else
		result = ft_strsub(s, (unsigned int)offset, (roffset - offset + 1));
	return (result);
}
