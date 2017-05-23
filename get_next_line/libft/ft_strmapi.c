/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:06:25 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/18 00:48:03 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*result;

	if (!s || !f)
		return (NULL);
	index = -1;
	result = (char *)malloc(sizeof(*result) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[++index])
		result[index] = f((unsigned int)index, s[index]);
	result[index] = 0;
	return (result);
}
