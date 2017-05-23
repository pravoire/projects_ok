/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 04:33:17 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:09:47 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strexp(char *s, size_t size)
{
	char		*s_tmp;

	if (!s)
	{
		if (!(s_tmp = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_bzero(s_tmp, size);
	}
	else
	{
		if (size < ft_strlen(s))
			return (NULL);
		if (!(s_tmp = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		s_tmp = ft_strcpy(s_tmp, s);
		free(s);
		s = NULL;
		return (s_tmp);
	}
	free(s);
	return (s_tmp);
}
