/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:46:47 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/18 17:50:30 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		print_notes(void)
{
	ft_putendl("FDF USAGE :");
	ft_putendl("----------------------------");
	ft_putendl("Arrow keys : move camera");
	ft_putendl("Pg up / down : zoom in / out");
	ft_putendl("!! Zoom x4 max !!");
	ft_putendl("Home : reset zoom and camera");
	ft_putendl("Esc : quit program");
	ft_putendl("----------------------------");
	ft_putendl("Enjoy ! ;)");
}

static void		init_win(t_env *e, char *arg)
{
	if (!(e->mlx = mlx_init()))
		error(2);
	if (!(e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, arg)))
		error(3);
}

static void		init_map(t_env *e, char *arg)
{
	int			i;

	get_map_size(e, arg);
	if (!(e->map = (t_pts **)malloc(sizeof(t_pts *) * e->map_h + 1)))
		error(1);
	i = 0;
	while (i < e->map_h)
	{
		if (!(e->map[i] = (t_pts *)malloc(sizeof(t_pts) * e->map_w + 1)))
			error(1);
		i++;
	}
	get_map_pts(e, arg);
}

static void		init_env(t_env *e)
{
	e->z_min = 0;
	e->z_max = 0;
	e->map_h = 0;
	e->map_w = -1;
	e->x0 = WIN_W / 2;
	e->y0 = WIN_H / 2;
	e->scl = Z_STEP;
}

int				main(int ac, char **av)
{
	t_env		e;

	if (ac != 2)
		error(0);
	init_env(&e);
	init_map(&e, av[1]);
	init_win(&e, av[1]);
	print_notes();
	mlx_expose_hook(e.win, expose_hook, (void *)&e);
	mlx_hook(e.win, 2, 3, key_hook, (void *)&e);
	mlx_loop(e.mlx);
	return (0);
}
