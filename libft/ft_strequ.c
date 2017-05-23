/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:11:26 by pravoire          #+#    #+#             */
/*   Updated: 2014/11/05 02:15:50 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] && (s1[index] == s2[index]))
		index++;
	if (s1[index] == s2[index])
		return (1);
	else
		return (0);
}
