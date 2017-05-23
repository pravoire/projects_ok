/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:34:15 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/18 00:08:56 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if ((elem->content = malloc(content_size)))
		{
			ft_memcpy(elem->content, content, content_size);
			elem->content_size = (size_t)content_size;
		}
		else
		{
			free(elem);
			return (NULL);
		}
	}
	elem->next = NULL;
	return (elem);
}
