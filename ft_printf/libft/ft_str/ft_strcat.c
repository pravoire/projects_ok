/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 02:48:24 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:09:03 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t		len;

	len = ft_strlen(dst);
	return (ft_strcpy(&dst[len], src) - len);
}
