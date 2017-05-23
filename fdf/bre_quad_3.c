/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bre_quad_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:12:17 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/04 18:43:14 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	oct_6(t_env *e, t_pts p1, t_pts p2)
{
	float	dx;
	float	dy;
	float	a;

	dx = p2.x_i - p1.x_i;
	dy = p2.y_i - p1.y_i;
	a = dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		draw_pts(e, p1, p2);
		if (--p1.y_i == p2.y_i)
			break ;
		if ((a -= dx) >= 0)
		{
			p1.x_i--;
			a += dy;
		}
	}
}

static void	oct_5(t_env *e, t_pts p1, t_pts p2)
{
	float	dx;
	float	dy;
	float	a;

	dx = p2.x_i - p1.x_i;
	dy = p2.y_i - p1.y_i;
	a = dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		draw_pts(e, p1, p2);
		if (--p1.x_i == p2.x_i)
			break ;
		if ((a -= dy) >= 0)
		{
			p1.y_i--;
			a += dx;
		}
	}
}

void		quad_3(t_env *e, t_pts p1, t_pts p2)
{
	float	dx;
	float	dy;

	dx = p2.x_i - p1.x_i;
	dy = p2.y_i - p1.y_i;
	if (dx <= dy)
		oct_5(e, p1, p2);
	else
		oct_6(e, p1, p2);
}
