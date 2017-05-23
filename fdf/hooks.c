/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:55:05 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/18 18:02:53 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		zoom(t_env *e, int key)
{
	if ((e->scl >= Z_STEP * 4) || (e->scl <= Z_STEP))
		return (0);
	if (key == Z_UP)
		e->scl += Z_STEP;
	else
		e->scl -= Z_STEP;
	return (0);
}

static void		destroy_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int				expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		destroy_win(e);
	if (keycode == M_UP)
		e->y0 += e->scl;
	else if (keycode == M_DOWN)
		e->y0 -= e->scl;
	else if (keycode == M_LEFT)
		e->x0 += e->scl;
	else if (keycode == M_RIGHT)
		e->x0 -= e->scl;
	else if (keycode == Z_UP || keycode == Z_DOWN)
		zoom(e, keycode);
	else if (keycode == Z_RESET)
	{
		e->scl = Z_STEP;
		e->x0 = WIN_W / 2;
		e->y0 = WIN_H / 2;
	}
	draw(e);
	return (0);
}
