/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:50:02 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/05 02:58:28 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	else
	{
		res = f(lst);
		if (!res)
			return (NULL);
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}
