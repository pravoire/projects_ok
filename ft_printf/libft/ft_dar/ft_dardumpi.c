/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardumpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:09:19 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:02:21 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

void		ft_ardumpi(t_dar *ar, t_uint i)
{
	size_t	j;

	j = 0;
	ft_printf("adress: %p\t|", ar->address[i].data);
	while (j < ar->address[i].size)
	{
		ft_printf("%d|", *((t_uchar *)(ar->address[i].data + j)));
		j++;
	}
	ft_printf("\n");
}
