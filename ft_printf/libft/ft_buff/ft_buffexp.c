/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:57:43 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:59:14 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_buffexp(t_buff **buff, size_t buff_size)
{
	char	buff_cpy[buff_size];

	if (!buff || !*buff)
		return ;
	ft_strcpy(buff_cpy, (*buff)->buff);
	ft_memdel((void **)&((*buff)->buff));
	if (!((*buff)->buff = (char *)malloc(sizeof(char) * buff_size + 1)))
		return ;
	ft_strcpy((*buff)->buff, buff_cpy);
	(*buff)->buff_size = buff_size;
}
