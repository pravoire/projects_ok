/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:35:01 by pravoire          #+#    #+#             */
/*   Updated: 2015/11/30 19:54:14 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	else
	{
		if ((result = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			result = ft_strcat(result, s1);
			result = ft_strcat(result, s2);
		}
	}
	return (result);
}
