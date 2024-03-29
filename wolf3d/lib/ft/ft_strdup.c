/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 11:41:45 by pravoire          #+#    #+#             */
/*   Updated: 2015/11/27 12:43:02 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		ite;

	ite = ft_strlen(s);
	if ((s_cpy = (char *)malloc(sizeof(char) * ite + 1)) != NULL)
	{
		ft_memcpy(s_cpy, s, ite);
		s_cpy[ite] = '\0';
		return (s_cpy);
	}
	return (NULL);
}
