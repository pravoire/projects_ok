/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:41:28 by pravoire          #+#    #+#             */
/*   Updated: 2015/11/24 17:48:10 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\r' || \
			c == '\f' || c == '\v')
		return (1);
	return (0);
}
