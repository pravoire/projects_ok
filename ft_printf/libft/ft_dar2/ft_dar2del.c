/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dar2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:16:06 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:03:29 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar2.h"

int			ft_dar2del(t_dar2 *dar)
{
	t_uint	i;

	i = 0;
	while (i < dar->size)
	{
		if (dar->del)
			dar->del(dar->ar[i]);
		free(dar->ar[i]);
		i++;
	}
	free(dar->ar);
	ft_bzero(dar, sizeof(t_dar2));
	return (1);
}
