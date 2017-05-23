/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:34:15 by pravoire          #+#    #+#             */
/*   Updated: 2015/12/05 02:20:17 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(*elem))))
	{
		if (content == NULL)
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		else
		{
			if ((elem->content = malloc(content_size)))
			{
				elem->content = ft_memcpy(elem->content, content, content_size);
				elem->content_size = content_size;
			}
			else
			{
				free(elem);
				return (NULL);
			}
		}
		elem->next = NULL;
	}
	return (elem);
}
