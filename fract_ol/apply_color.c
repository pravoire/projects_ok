/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:39:05 by pravoire          #+#    #+#             */
/*   Updated: 2016/09/28 07:39:41 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_apply(t_env *e, t_fractol *fractoltal, \
		int (*f)(t_env *e, t_fractol, t_point*))
{
	t_point	pt;
	int		col_pix;

	pt.y = 0;
	while (pt.y < e->height)
	{
		pt.x = 0;
		while (pt.x < e->width)
		{
			col_pix = (*f)(e, *fractoltal, &pt);
			pixel_draw_img(&(pt), e, col_pix);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
}
