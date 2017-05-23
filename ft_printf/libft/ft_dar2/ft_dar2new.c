/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dar2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:17:05 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:03:44 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar2.h"

int	ft_dar2new(t_dar2 *dar, size_t size, t_dar_del del)
{
	ft_bzero((void *)dar, sizeof(t_dar2));
	dar->ar = (void **)ft_memalloc(sizeof(void *) * DAR2_OFFSET);
	if (!dar->ar)
		return (1);
	dar->size_content = size;
	dar->size_max = DAR2_OFFSET;
	if (del)
		dar->del = del;
	return (0);
}
