/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:00:09 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:09:59 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	t_uint		i;

	if (!s || !f)
		return ;
	i = MAX_UINT;
	while (s[++i])
		f(i, &(s[i]));
}
