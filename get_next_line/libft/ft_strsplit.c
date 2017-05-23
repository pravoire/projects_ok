/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 03:12:24 by pravoire          #+#    #+#             */
/*   Updated: 2015/11/30 19:59:46 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnbsubstr(char const *s, char c)
{
	size_t	index;
	size_t	result;

	index = 0;
	result = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != 0)
			result++;
		while (s[index] != c && s[index])
			index++;
	}
	return (result);
}

static	void	ft_getsublen(char const *s, char c, size_t *sub)
{
	size_t	index;
	size_t	offset;
	size_t	subindex;

	index = 0;
	subindex = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		offset = index;
		while (s[index] != c && s[index])
			index++;
		sub[subindex++] = index - offset + 1;
	}
}

static	void	ft_initresult(char **res, size_t nbsub, size_t *sublen)
{
	size_t	subindex;

	subindex = -1;
	while (++subindex < nbsub)
		res[subindex] = ft_strnew(sublen[subindex]);
	res[subindex] = NULL;
}

static	void	ft_split(char const *s, char c, char **res)
{
	size_t	index;
	size_t	subindex;

	index = 0;
	subindex = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			res[subindex][index++] = *s++;
		index = 0;
		subindex++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	char	*temp;
	size_t	nbsubstr;
	size_t	*sublen;

	result = NULL;
	if (s)
	{
		temp = (char *)s;
		nbsubstr = ft_getnbsubstr(temp, c);
		if ((sublen = (size_t *)malloc(sizeof(*sublen) * nbsubstr)))
		{
			ft_getsublen(s, c, sublen);
			if ((result = (char **)malloc(sizeof(*result) * (nbsubstr + 1))))
				if (result)
				{
					ft_initresult(result, nbsubstr, sublen);
					ft_split(s, c, result);
				}
		}
	}
	return (result);
}
