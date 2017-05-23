/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membzdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:18:45 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:06:17 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	ft_membzdel(void **ap, size_t n)
{
	if (!ap)
		return ;
	ft_bzero(*ap, n);
	ft_memdel(ap);
}