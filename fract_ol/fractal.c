/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:40:50 by pravoire          #+#    #+#             */
/*   Updated: 2017/05/09 15:38:15 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_env *e)
{
	if (!(e->array = (t_fractol *)malloc(sizeof(t_fractol) * 5)))
		param_error(1);
	e->ptr = NULL;
	e->array[0] = (t_fractol){{0, 0}, {0, 0}, -0.9, 0, 0, 0, \
		e->width / 2.7, e->height / 2.4, 0.5, 0, 0, 50, mandelbrot};
	e->array[1] = (t_fractol){{0.285, 0.01}, {0, 0}, 0, 0, 0, 0, \
		e->width / 3.0, e->height / 2.4, 0.5, 0, 0, 10, julia};
	e->array[2] = (t_fractol){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2, \
		e->width / 2.7, e->height / 2.4, 1, 0, 0, 50, menger};
	e->array[3] = (t_fractol){{0, 0}, {0, 0}, 0, 0, 0, 0, \
		e->width / 2.7, e->height / 2.4, 0.5, 0, 0, 50, b_ship};
	e->array[4] = (t_fractol){{0, 0}, {0, 0}, 0, 0, 0, 0, \
		e->width / 2.7, e->height / 2.4, 0.5, 0, 0, 50, mandelbar};
	e->ptr = &(e->array[0]);
}

int		mandelbrot(t_env *e, t_fractol fractal, t_point *pt)
{
	fractal.c.r = 1.0 * (pt->x - e->width / 2) /
		(0.5 * fractal.zoom_ratio * e->width) + fractal.x1;
	fractal.c.im = (pt->y - e->height / 2) /
		(0.5 * fractal.zoom_ratio * e->height) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.im * fractal.z.im < 4) \
				&& (fractal.ite < fractal.ite_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.im * \
					fractal.z.im + fractal.c.r;
		fractal.z.im = 2 * fractal.z.im * fractal.tmp + fractal.c.im;
		fractal.ite += 1;
	}
	if (fractal.ite == fractal.ite_max)
		return (get_color(100, *(e->col_ptr)));
	return (get_color((fractal.ite * fractal.ite) * 0.1, *(e->col_ptr)));
}

int		mandelbar(t_env *e, t_fractol fractal, t_point *pt)
{
	fractal.c.r = 1.0 * (pt->x - e->width / 2) /
		(0.5 * fractal.zoom_ratio * e->width) + fractal.x1;
	fractal.c.im = (pt->y - e->height / 2) /
		(0.5 * fractal.zoom_ratio * e->height) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.im * fractal.z.im < 4) \
				&& (fractal.ite < fractal.ite_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.im *= -1;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.im * \
					fractal.z.im + fractal.c.r;
		fractal.z.im = 2 * fractal.z.im * fractal.tmp + fractal.c.im;
		fractal.ite += 1;
	}
	if (fractal.ite == fractal.ite_max)
		return (get_color(100, *(e->col_ptr)));
	return (get_color((fractal.ite * fractal.ite) * 0.1, *(e->col_ptr)));
}

int		julia(t_env *e, t_fractol fractal, t_point *pt)
{
	fractal.z.r = 1.0 * (pt->x - e->width / 2) /
		(0.5 * fractal.zoom_ratio * e->width) + fractal.x1;
	fractal.z.im = (pt->y - e->height / 2) /
		(0.5 * fractal.zoom_ratio * e->height) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.im * fractal.z.im < 4) \
				&& (fractal.ite < fractal.ite_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.im * \
					fractal.z.im + fractal.c.r;
		fractal.z.im = 2 * fractal.z.im * fractal.tmp + fractal.c.im;
		fractal.ite += 1;
	}
	if (fractal.ite == fractal.ite_max)
		return (get_color(100, *(e->col_ptr)));
	return (get_color((fractal.ite * fractal.ite) * 0.1, *(e->col_ptr)));
}

int		b_ship(t_env *e, t_fractol fractal, t_point *pt)
{
	(void)e;
	fractal.c.r = 1.0 * (pt->x - e->width / 2) /
		(0.5 * fractal.zoom_ratio * e->width) + fractal.x1;
	fractal.c.im = (pt->y - e->height / 2) /
		(0.5 * fractal.zoom_ratio * e->height) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.im * fractal.z.im < 4) \
				&& (fractal.ite < fractal.ite_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.im * \
					fractal.z.im + fractal.c.r;
		fractal.z.im = 2 * fabs(fractal.z.im) * fabs(fractal.tmp) + \
					fractal.c.im;
		fractal.ite += 1;
	}
	if (fractal.ite == fractal.ite_max)
		return (rgb_creating(fractal.ite * 255 / fractal.ite_max, 10, 0));
	return (rgb_creating(fractal.ite * 255 / fractal.ite_max, fractal.ite * \
				255 / (fractal.ite_max * 2), 0));
}
