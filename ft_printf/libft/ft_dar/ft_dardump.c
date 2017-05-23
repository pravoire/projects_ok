/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:14:27 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:02:13 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

void		ft_ardump(t_dar *ar)
{
	size_t	i;

	i = 0;
	ft_printf("\nDUMP AR:\ndata: %p\ncurr: %p\nend: %p\naddress: %p\nsize: \
	%zu\ni: %u\n\n", ar->data, ar->curr, ar->end, ar->address, ar->size, ar->i);
	while (i < ar->i)
	{
		ft_printf("\t");
		ft_dardumpi(ar, i);
		i++;
	}
	ft_printf("\nEND DUMP\n");
}
