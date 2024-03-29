/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:14:38 by pravoire          #+#    #+#             */
/*   Updated: 2015/11/26 12:29:27 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	return (str);
}
