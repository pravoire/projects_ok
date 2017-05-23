/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:49:21 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:05:06 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void		ft_lstadd_back(t_list **alst, t_list *elem)
{
	t_list		*drive;

	if (!elem || !alst)
		return ;
	drive = *alst;
	if (drive)
	{
		while (drive->next)
			drive = drive->next;
		drive->next = elem;
	}
	else
		*alst = elem;
}
