/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:14:58 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/04 19:42:32 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		translate(t_env *e)
{
	int			y;
	int			x;

	y = -1;
	while (++y < e->map_h)
	{
		x = -1;
		while (++x < e->map_w)
		{
			e->map[y][x].x_i -= (e->x_min * e->scl);
			e->map[y][x].y_i -= (e->y_min * e->scl);
		}
	}
}

t_pts			pt_to_iso(t_env *e, float x, float y, int z)
{
	t_pts		pt;

	if (z == -2147483648)
	{
		pt.x_i = (x - y) * e->scl;
		pt.y_i = ((x + y) / 2) * e->scl;
		pt.z = z;
	}
	else
	{
		pt.x_i = (x - y) * e->scl;
		pt.y_i = ((x + y) / 2 - z) * e->scl;
		pt.z = z;
	}
	return (pt);
}

void			map_to_iso(t_env *e)
{
	int			y;
	int			x;

	y = 0;
	while (y < e->map_h)
	{
		x = 0;
		while (x < e->map_w)
		{
			e->map[y][x] = pt_to_iso(e, x, y, e->map[y][x].z);
			if ((e->map[y][x].x_i / e->scl) > e->x_max)
				e->x_max = (e->map[y][x].x_i / e->scl);
			if ((e->map[y][x].x_i / e->scl) < e->x_min)
				e->x_min = (e->map[y][x].x_i / e->scl);
			if ((e->map[y][x].y_i / e->scl) > e->y_max)
				e->y_max = (e->map[y][x].y_i / e->scl);
			if ((e->map[y][x].y_i / e->scl) < e->y_min)
				e->y_min = (e->map[y][x].y_i / e->scl);
			x++;
		}
		y++;
	}
	e->img_w = e->x_max - e->x_min + 1;
	e->img_h = e->y_max - e->y_min + 1;
	translate(e);
}
