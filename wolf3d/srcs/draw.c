/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:22:59 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/09 16:01:12 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			put_pixel(t_env *e, int x, int y, unsigned int color)
{
	int				i;

	i = (x * 4) + (y * e->mlx.size_line);
	e->mlx.data[i] = color;
	e->mlx.data[i + 1] = color >> 8;
	e->mlx.data[i + 2] = color >> 16;
}

static unsigned int	get_color(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) || \
				(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->col_north_wall);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) || \
				(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->col_south_wall);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) || \
			(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->col_east_wall);
	return (e->col_west_wall);
}

static unsigned int	shadow(unsigned int color, double d)
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;

	red = color;
	green = color >> 8;
	blue = color >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (red > 0)
		red = red - (red * d);
	if (green > 0)
		green = green - (green * d);
	if (blue > 0)
		blue = blue - (blue * d);
	return ((red << 16) + (green << 8) + blue);
}

void				draw_line(t_env *e, int x, int start, int end)
{
	int				i;
	unsigned int	color;

	color = get_color(e);
	color = shadow(color, e->ray.dist);
	i = -1;
	while (++i < start + e->player.z)
		put_pixel(e, x, i, e->col_sky);
	i--;
	while (++i <= end + e->player.z && i < e->height)
		put_pixel(e, x, i, color);
	i--;
	while (++i < e->height)
		put_pixel(e, x, i, shadow(e->col_ground, abs(i - e->height) * 0.040));
}
