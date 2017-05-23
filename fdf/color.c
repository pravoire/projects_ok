/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 09:40:35 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/10 19:16:59 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			rgb_warm(t_env *e, int z)
{
	e->rgb[2] = z;
	e->rgb[1] = 255 - z;
	e->rgb[0] = 0;
}

static void			rgb_neut(t_env *e)
{
	e->rgb[2] = 0;
	e->rgb[1] = 255;
	e->rgb[0] = 0;
}

static void			rgb_cold(t_env *e, int z)
{
	e->rgb[2] = 0;
	e->rgb[1] = 255 + z;
	e->rgb[0] = -z;
}

void				get_pt_color(t_env *e, t_pts p1, t_pts p2)
{
	int				z;

	if (p1.z >= p2.z)
		z = p1.z * 20;
	else
		z = p2.z * 20;
	if (z > 255)
		z = 255;
	else if (z < -255)
		z = -255;
	if (z > 0)
		rgb_warm(e, z);
	else if (z < 0)
		rgb_cold(e, z);
	else
		rgb_neut(e);
}
