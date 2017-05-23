/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:21:47 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:11:55 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strupper(char *const s)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		*cp = ft_toupper(*cp);
		cp++;
	}
	return (s);
}
