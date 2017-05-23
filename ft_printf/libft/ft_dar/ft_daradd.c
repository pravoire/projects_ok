/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aradd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:27:22 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 20:01:52 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

static void	ar_majaddr(t_dar *ar)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = ar->data;
	while (i < ar->i)
	{
		ar->address[i].data = tmp;
		tmp += ar->address[i].size;
		i++;
	}
}

static int	ar_init(t_dar *ar, size_t size)
{
	ar->data = ft_memalloc(size * 2);
	if (!ar->data)
		return (1);
	ar->address = (t_cel *)ft_memalloc(sizeof(t_cel) * 2);
	if (!ar->address)
	{
		free(ar->data);
		return (1);
	}
	ar->curr = ar->data;
	ar->end = ar->curr + (size * 2);
	ar->size = 2;
	return (0);
}

static int	ar_expdata(t_dar *ar)
{
	void	*tmp;
	size_t	size;

	tmp = ar->data;
	size = ar->end - ar->data;
	ar->data = ft_memalloc(size * 2);
	if (!ar->data)
	{
		free(tmp);
		free(ar->address);
		return (0);
	}
	ft_memcpy(ar->data, tmp, size);
	ar->curr = ar->data + (ar->curr - tmp);
	ar->end = ar->data + (size * 2);
	free(tmp);
	ar_majaddr(ar);
	return (1);
}

static int	ar_expcel(t_dar *ar)
{
	t_cel	*tmp;

	tmp = ar->address;
	ar->address = (t_cel *)ft_memalloc((sizeof(t_cel) * ar->size) * 2);
	if (!ar->address)
	{
		free(tmp);
		free(ar->data);
		return (0);
	}
	ft_memcpy(ar->address, tmp, (sizeof(t_cel) * ar->size));
	ar->size *= 2;
	free(tmp);
	return (1);
}

int			ft_daradd(t_dar *ar, void *data, size_t size)
{
	if (!ar->size)
	{
		if (ar_init(ar, size))
			return (1);
	}
	else
	{
		while ((size + ar->curr) > ar->end)
		{
			if (!ar_expdata(ar))
				return (1);
		}
		if (ar->size && ar->i >= ar->size && !ar_expcel(ar))
		{
			return (1);
		}
	}
	ar->address[ar->i].data = ar->curr;
	ar->address[ar->i].size = size;
	ft_memcpy(ar->curr, data, size);
	ar->curr += size;
	ar->i++;
	return (0);
}
