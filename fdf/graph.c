/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:36:32 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/10 20:04:19 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					draw_pts(t_env *e, t_pts p1, t_pts p2)
{
	int					index;

	get_pt_color(e, p1, p2);
	index = p1.x_i * e->bpp / 8 + p1.y_i * e->s_l;
	e->data[index] = e->rgb[0];
	e->data[index + 1] = e->rgb[1];
	e->data[index + 2] = e->rgb[2];
}

static void				draw_last_row(t_env *e)
{
	int					i;
	int					j;

	i = 0;
	j = e->map_h - 1;
	while (i < e->map_w - 1)
	{
		if ((e->map[j][i].z != -2147483648)
			|| (e->map[j][i + 1].z != -2147483648))
			draw_line(e, e->map[j][i], e->map[j][i + 1]);
		i++;
	}
}

static void				draw_last_col(t_env *e)
{
	int					i;
	int					j;

	i = e->map_w - 1;
	j = 0;
	while (j < e->map_h - 1)
	{
		if ((e->map[j][i].z != -2147483648)
			|| (e->map[j + 1][i].z != -2147483648))
			draw_line(e, e->map[j][i], e->map[j + 1][i]);
		j++;
	}
}

static void				draw_map(t_env *e)
{
	int					i;
	int					j;

	j = 0;
	while (j < e->map_h - 1)
	{
		i = 0;
		while (i < e->map_w - 1)
		{
			if (e->map[j][i].z != -2147483648)
			{
				if (e->map[j][i + 1].z != -2147483648)
					draw_line(e, e->map[j][i], e->map[j][i + 1]);
				if (e->map[j + 1][i].z != -2147483648)
					draw_line(e, e->map[j][i], e->map[j + 1][i]);
			}
			i++;
		}
		j++;
	}
	draw_last_row(e);
	draw_last_col(e);
	draw_pts(e, e->map[j][i], e->map[j][i]);
}

void					draw(t_env *e)
{
	int					x;
	int					y;

	mlx_clear_window(e->mlx, e->win);
	e->x_min = 0;
	e->x_max = 0;
	e->y_min = 0;
	e->y_max = 0;
	map_to_iso(e);
	e->img_w *= e->scl;
	e->img_h *= e->scl;
	e->img = mlx_new_image(e->mlx, e->img_w, e->img_h);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->end));
	draw_map(e);
	x = e->x0 - e->img_w / 2;
	y = e->y0 - e->img_h / 2;
	mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
}
