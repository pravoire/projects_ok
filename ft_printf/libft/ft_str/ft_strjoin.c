/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:43:44 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:10:04 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		len = ft_strlen(s2);
	else if (!s2)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!s1)
		return (ft_strcpy(dst, s2));
	else if (!s2)
		return (ft_strcpy(dst, s1));
	else
		ft_strcpy(dst, s1);
	return (ft_strcat(dst, s2));
}
