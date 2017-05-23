/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:46:03 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:59:23 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff		*ft_buffnew(int fd, size_t buff_size)
{
	t_buff		*new;

	if (!(new = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	new->ret = 0;
	new->fd = fd;
	new->buff_size = buff_size;
	if (!(new->buff = ft_strnew(buff_size)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}
