/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:35:36 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:45:26 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				save_buf(void *buf, size_t size)
{
	t_list			*cp;

	if (!size)
		return ;
	cp = ft_lstnew(buf, size);
	if (!cp)
		return ;
	ft_lstadd_back(buflist(), cp);
}
