/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:36:02 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:59:05 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_buffdel(t_buff **buff)
{
	if (!buff || !*buff)
		return ;
	if ((*buff)->buff)
		ft_memdel((void **)&(*buff)->buff);
	ft_memdel((void **)buff);
}
