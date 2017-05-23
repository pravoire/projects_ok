/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 07:12:37 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/04 21:28:31 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		quad_23(t_env *e, t_pts p1, t_pts p2)
{
	float		dy;

	dy = p2.y_i - p1.y_i;
	if (dy > 0)
		quad_2(e, p1, p2);
	else if (dy < 0)
		quad_3(e, p1, p2);
	else
		while (p1.x_i < p2.x_i)
		{
			draw_pts(e, p1, p2);
			p1.x_i--;
		}
}

static void		quad_14(t_env *e, t_pts p1, t_pts p2)
{
	float		dy;

	dy = p2.y_i - p1.y_i;
	if (dy > 0)
		quad_1(e, p1, p2);
	else if (dy < 0)
		quad_4(e, p1, p2);
	else
		while (p1.x_i < p2.x_i)
		{
			draw_pts(e, p1, p2);
			p1.x_i++;
		}
}

void			draw_line(t_env *e, t_pts p1, t_pts p2)
{
	float		dx;
	float		dy;

	if ((dx = p2.x_i - p1.x_i) > 0)
		quad_14(e, p1, p2);
	else if ((dx = p2.x_i - p1.x_i) < 0)
		quad_23(e, p1, p2);
	else
	{
		if ((dy = p2.y_i - p1.y_i) != 0)
		{
			if (dy > 0)
				while (p1.y_i < p2.y_i)
				{
					draw_pts(e, p1, p2);
					p1.y_i++;
				}
			else
				while (p1.y_i > p2.y_i)
				{
					draw_pts(e, p1, p2);
					p1.y_i--;
				}
		}
	}
}
