/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:32:55 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/05 02:16:55 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (del)
		{
			del((*alst)->content, (*alst)->content_size);
		}
		free((*alst)->content);
		(*alst)->content = NULL;
		free(*alst);
		*alst = NULL;
	}
}
