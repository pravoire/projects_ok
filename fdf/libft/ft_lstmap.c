/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:50:02 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/17 22:34:34 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*cpy;

	cpy = lst;
	if (!cpy || !f)
		return (NULL);
	else
	{
		if (!(res = f(cpy)))
			return (NULL);
		res->next = ft_lstmap(cpy->next, f);
		if (!res->next && cpy->next)
		{
			ft_lstdelone(&res, NULL);
			return (NULL);
		}
	}
	return (res);
}
